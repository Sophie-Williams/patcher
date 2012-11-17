
#include <boost/filesystem.hpp>
#include <boost/crc.hpp>
#include <boost/regex.hpp> 

#include <deque>
#include <string>
#include <fstream>

#include "patch_file.h"
#include "file_manager.h"


class PatchList
{
public:
    void generate_patch_files(std::string ignore_regex_str = "[\\d\\w]+\\.(cpp|h|obj)|makefile");

protected:
    void parse_directory(std::string dir);
    void write_patch_file(std::string dir = "patch", std::string filename = "patch.txt");

public:
    boost::regex ignore_regex;
    std::string current_directory;
    std::deque<PatchFile> files;
    std::deque<std::string> directories;
};