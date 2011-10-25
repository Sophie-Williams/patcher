
#include <boost/filesystem.hpp>
#include <boost/crc.hpp>

#include <deque>
#include <string>

#include "patch_file.h"
#include "file_manager.h"


class PatchList
{
public:
    void generate_patch_files();

protected:
    void parse_directory(std::string dir);

public:
    std::string current_directory;
    std::deque<PatchFile> files;
    std::deque<std::string> directories;
};