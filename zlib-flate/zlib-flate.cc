#include <qpdf/Pl_Flate.hh>
#include <qpdf/Pl_StdioFile.hh>
#include <qpdf/QPDF.hh>
#include <qpdf/QUtil.hh>

#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char const* whoami = 0;

void
usage()
{
    std::cerr << "Usage: " << whoami << " { -uncompress | -compress[=n] }"
              << std::endl
              << "If n is specified with -compress, it is a"
              << " zlib compression level from" << std::endl
              << "1 to 9 where lower numbers are faster and"
              << " less compressed and higher" << std::endl
              << "numbers are slower and more compressed" << std::endl;
    exit(2);
}

int
main(int argc, char* argv[])
{
    if ((whoami = strrchr(argv[0], '/')) == NULL) {
        whoami = argv[0];
    } else {
        ++whoami;
    }

    if ((argc == 2) && (strcmp(argv[1], "--version") == 0)) {
        std::cout << whoami << " from qpdf version " << QPDF::QPDFVersion()
                  << std::endl;
        exit(0);
    }

    if (argc != 2) {
        usage();
    }

    Pl_Flate::action_e action = Pl_Flate::a_inflate;

    if ((strcmp(argv[1], "-uncompress") == 0)) {
        // okay
    } else if ((strcmp(argv[1], "-compress") == 0)) {
        action = Pl_Flate::a_deflate;
    } else if ((strncmp(argv[1], "-compress=", 10) == 0)) {
        action = Pl_Flate::a_deflate;
        int level = QUtil::string_to_int(argv[1] + 10);
        Pl_Flate::setCompressionLevel(level);
    } else {
        usage();
    }

    QUtil::binary_stdout();
    QUtil::binary_stdin();
    auto out = std::make_shared<Pl_StdioFile>("stdout", stdout);
    auto flate = std::make_shared<Pl_Flate>("flate", out.get(), action);
    bool warn = false;
    flate->setWarnCallback([&warn](char const* msg, int code) {
        warn = true;
        std::cerr << whoami << ": WARNING: zlib code " << code
                  << ", msg = " << msg << std::endl;
    });

    try {
        unsigned char buf[10000];
        bool done = false;
        while (!done) {
            size_t len = fread(buf, 1, sizeof(buf), stdin);
            if (len <= 0) {
                done = true;
            } else {
                flate->write(buf, len);
            }
        }
        flate->finish();
    } catch (std::exception& e) {
        std::cerr << whoami << ": " << e.what() << std::endl;
        exit(2);
    }

    if (warn) {
        exit(3);
    }
    return 0;
}
