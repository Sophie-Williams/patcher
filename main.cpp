
#include <string>
#include <iostream>

#include "downloader.h"


int main(int argc, char* argv[]) {
    try {
	  	  Downloader downloader("www.leaiva.com", "80");
	  	  downloader.get("/client/test/asdads.txt", "3E71771B");

        downloader.run();
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    FileManager::rmdirs("tmp");
	
  	return 0;
}

