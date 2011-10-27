
#include "patch_manager.h"


void PatchManager::get_patch() 
{
    downloader.init("www.leaiva.com", "80", "/patch");
    download_patch_file();
    download_patch_contents();
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

    if(patch) {
        while(patch.good()) {
            getline(patch, line);
            
            index = line.find(" ");
            if(index != std::string::npos) {
                downloader.get(line.substr(0, index), line.substr(index + 1));
            }
            else {
                std::cout << "Invalid patch file line: " << line_num << std::endl;
                patch.close();
                return;
            }

            ++line_num;
        }
        
        patch.close();
    }
    else {
        std::cout << "Could not open local patch file in patch/patch.txt" << std::endl;
    }
}