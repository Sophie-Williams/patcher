
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

void FileManager::mkdirs(std::string dir)
{
		create_directories(dir);
}

void FileManager::rmdirs(std::string dir)
{	
		if(directory_exists(dir)) {
				path p(dir);
				remove_all(p);
		}
}

void FileManager::rm(std::string file)
{
		if(file_exists(file)) {
				path p(file);
				remove(p);
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

std::string FileManager::checksum(std::string file_path) 
{
		if(file_exists(file_path)) {
				std::string content = "";
				std::string line = "";
				std::ifstream file(file_path.c_str());

				if(file) {
						while(file.good()) {
								std::getline(file, line);
								content += line;
						}	
				}

				boost::crc_32_type result;
				result.process_bytes(content.data(), content.length());
				
				std::stringstream ss;
				ss << std::hex << std::uppercase << result.checksum();
				return ss.str();
		}

		return "";
}

void FileManager::mv(std::string source, std::string destination)
{
		path src(source);
		path dest(destination);
		rename(src, dest);
}



