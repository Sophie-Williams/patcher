
#include "file_manager.h"


bool FileManager::directory_exists(std::string dir)
{
	path p(dir);

	if(exists(p)) {
		if(is_directory(p)) {
			return true;
		}
	}

	return false;
}

bool FileManager::file_exists(std::string file)
{
	path p(file);

	if(exists(p)) {
		if(is_regular_file(p)) {
			return true;
		}
	}

	return false;
}

void FileManager::makedir(std::string dir)
{
	if(!directory_exists(dir)) {
		create_directory(dir);	
	}
}

void FileManager::rmdir(std::string dir)
{	
	if(directory_exists(dir)) {
		path p(dir);
		remove_all(p);
	}
}


void FileManager::write(std::string& content, std::string file_path)
{
	std::ofstream file(file_path.c_str());
	if(file) {
		file << content;
		file.close();
	}
}


