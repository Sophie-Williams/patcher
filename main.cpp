
#include <string>
#include <iostream>

#include "patch_manager.h"
#include "patch_list.h"


int main(int argc, char* argv[]) {
    std::cout << std::endl;

    try {
        // Builds a patch list from local files
        PatchList p;
        // Pass in a regex to determine which files to ignore
        p.generate_patch_files("[\\d\\w]+\\.(cpp|h|obj)|makefile");

        // Gets patch
        PatchManager patch_manager;
        // Pass in a list of files to ignore
        patch_manager.get_patch("www.leaiva.com", "80", "/patch", "[\\d\\w]+\\.(cpp|h|obj)|makefile");
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    FileManager::rmdirs("tmp");
	
    std::cout << std::endl;
  	return 0;
}

