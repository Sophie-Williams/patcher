
#include <string>

#include "downloader.h"
#include "file_manager.h"
#include <boost/regex.hpp> 


class PatchManager
{
public:
    void get_patch(
      std::string domain, 
      std::string port, 
      std::string starting_uri_dir, 
      std::string ignore_str = "[\\d\\w]+\\.(cpp|h|obj)|makefile"
    );

protected:
    void load();
    void download_patch_file();
    void download_patch_contents();

protected:
    std::string domain, port, starting_uri_dir;
    Downloader downloader;
    boost::regex ignore_regex;
};