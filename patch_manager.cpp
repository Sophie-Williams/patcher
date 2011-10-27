
#include "patch_manager.h"


void PatchManager::get_patch() 
{
    downloader.init("www.leaiva.com", "80", "/patch");
    download_patch_file();
    download_patch_contents();

    std::cout << std::endl;
    std::cout << "Patch list found" << std::endl;
    //downloader.run();
}

void PatchManager::download_patch_file()
{
    downloader.get("/patch.txt");
    downloader.run();
}


void PatchManager::download_patch_contents()
{ 
    std::string line = "";
    std::ifstream patch("patch/patch.txt");
    int index;
    int line_num = 0;
    std::string checksum;
    std::string filename;

    if(patch) {
        while(patch.good()) {
            getline(patch, line);

            if(line.empty()) {
                continue;
            }
            
            index = line.find(" ");
            if(index != std::string::npos) {
                filename = line.substr(0, index);
                checksum = line.substr(index + 1);

                // If the local file's checksum doesn't match the 
                // checksum on the patch file, we know that the file is 
                // out of date, so download it.
                if(checksum != FileManager::checksum(filename)) {
                    downloader.get(filename, checksum);
                }
            }
            else {
                std::cout << std::endl << "Invalid line in patch file: " << line_num << std::endl;
            }

            std::cout << ".";
            ++line_num;
        }
        
        patch.close();
    }
    else {
        std::cout << "Could not open local patch file in patch/patch.txt" << std::endl;
    }
}