
#include <boost/filesystem.hpp>
#include <boost/crc.hpp>
#include <fstream>
#include <sstream>

using namespace boost::filesystem;


class FileManager
{
public:
    static void mkdirs(std::string dir);
  	static void rmdirs(std::string dir);
    static void rm(std::string file);
    static void mv(std::string source, std::string destination);
    static bool directory_exists(std::string dir);
    static bool file_exists(std::string dir);
  	static void write(std::string& content, std::string file_path);
  	static std::string checksum(std::string file_path);
};