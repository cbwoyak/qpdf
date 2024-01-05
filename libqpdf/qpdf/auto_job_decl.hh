//
// This file is automatically generated by generate_auto_job.
// Edits will be automatically overwritten if the build is
// run in maintainer mode.
//
// clang-format off
//
static constexpr char const* O_PAGES = "pages";
static constexpr char const* O_ENCRYPTION = "encryption";
static constexpr char const* O_40_BIT_ENCRYPTION = "40-bit encryption";
static constexpr char const* O_128_BIT_ENCRYPTION = "128-bit encryption";
static constexpr char const* O_256_BIT_ENCRYPTION = "256-bit encryption";
static constexpr char const* O_UNDERLAY_OVERLAY = "underlay/overlay";
static constexpr char const* O_ATTACHMENT = "attachment";
static constexpr char const* O_COPY_ATTACHMENT = "copy attachment";
static constexpr char const* O_SET_PAGE_LABELS = "set page labels";

void argVersion();
void argCopyright();
void argShowCrypto();
void argJobJsonHelp();
void argJsonHelp(std::string const&);
void argPositional(std::string const&);
void argAddAttachment();
void argCopyAttachmentsFrom();
void argEmpty();
void argEncrypt();
void argOverlay();
void argPages();
void argReplaceInput();
void argSetPageLabels();
void argUnderlay();
void argPagesPositional(std::string const&);
void argPagesPassword(std::string const&);
void argEndPages();
void argEncPositional(std::string const&);
void argEncUserPassword(std::string const&);
void argEncOwnerPassword(std::string const&);
void argEncBits(std::string const&);
void argEndEncryption();
void argEnd40BitEncryption();
void argEnd128BitEncryption();
void argEnd256BitEncryption();
void argUOPositional(std::string const&);
void argEndUnderlayOverlay();
void argAttPositional(std::string const&);
void argEndAttachment();
void argCopyAttPositional(std::string const&);
void argEndCopyAttachment();
void argPageLabelsPositional(std::string const&);
void argEndSetPageLabels();
