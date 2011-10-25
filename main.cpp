
#include <string>
#include <iostream>

#include "downloader.h"
#include "patch_list.h"


int main(int argc, char* argv[]) {
    std::cout << std::endl;

    try {
        PatchList patch_list;
        patch_list.generate_patch_files();

    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    FileManager::rmdirs("tmp");
	
    std::cout << std::endl;
  	return 0;
}

