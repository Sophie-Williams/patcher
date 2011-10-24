
#include <boost/filesystem.hpp>
#include <fstream>

using namespace boost::filesystem;


class FileManager
{
public:
	static void makedir(std::string dir);
  static void rmdir(std::string dir);
	static bool directory_exists(std::string dir);
	static bool file_exists(std::string dir);
  static void write(std::string& content, std::string file_path);
};