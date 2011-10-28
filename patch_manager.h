
#include <string>

#include "downloader.h"
#include "file_manager.h"
#include <boost/regex.hpp> 


class PatchManager
{
public:
    void get_patch();

protected:
    void download_patch_file();
    void download_patch_contents();

protected:
    Downloader downloader;
    boost::regex ignore_regex;
};