
#include "patch_list.h"


void PatchList::generate_patch_files()
{
    files.clear();
    directories.clear();
    directories.push_back(".");
    current_directory = complete(path(".")).string() + "/";
    std::cout << "Current directory is: \n  " << current_directory << std::endl;


    while(!directories.empty()) {
        parse_directory(directories.front());
        directories.pop_front();
    }

    write_patch_file();
}

void PatchList::parse_directory(std::string dir)
{
    path p(dir);
    directory_iterator end;

    for(directory_iterator iter(p); iter != end; ++iter) {
        std::string path = complete(*iter).string();
        if(is_directory(*iter)) {
            directories.push_back(path);
        }
        else if(is_regular_file(*iter)) {
            std::string rel_path = path.substr(current_directory.size());
            files.push_back(PatchFile(rel_path, FileManager::checksum(path)));
        }
    }
}

void PatchList::write_patch_file(std::string filename)
{
    std::ofstream patch(filename.c_str());
    if(patch) {
        size_t sz = files.size();
        for(size_t i = 0; i < sz; ++i) {
            patch << files[i].string() << std::endl;
        }

        patch.close();
    }
}