
#include <string>
#include <iostream>
#include <sstream>
#include <boost/asio.hpp>

#include "file_manager.h"


using boost::asio::ip::tcp;


class Downloader 
{
public:
	Downloader(std::string host);
	void get(std::string uri, std::string local_path, std::string expected_checksum = "");

public:
	std::string host;
	boost::asio::io_service io_service;
	boost::system::error_code error;

protected:
	std::string get_checksum(std::string file);
};