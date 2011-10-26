
#include "patch_manager.h"


void PatchManager::get_patch() 
{
    downloader.init("www.leaiva.com", "80");
    download_patch_file();
    download_patch_contents();
}

void PatchManager::download_patch_file()
{
    downloader.get("patch/patch.txt");
    downloader.run();
}


void PatchManager::download_patch_contents()
{
    
}