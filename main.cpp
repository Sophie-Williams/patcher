
#include <string>
#include <iostream>

#include "patch_manager.h"


int main(int argc, char* argv[]) {
    std::cout << std::endl;

    try {
        PatchManager patch_manager;
        patch_manager.get_patch();
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    FileManager::rmdirs("tmp");
	
    std::cout << std::endl;
  	return 0;
}

