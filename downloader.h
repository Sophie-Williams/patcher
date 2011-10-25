
#include <string>
#include <iostream>
#include <sstream>
#include <deque>
#include <boost/asio.hpp>

#include "file_manager.h"
#include "file_to_download.h"

using boost::asio::ip::tcp;


class Downloader 
{
public:
    Downloader(std::string host);
    void get(std::string uri, std::string expected_checksum = "");
    void run();

protected:
    void _download(FileToDownload file);
    
public:
    std::string host;
    boost::asio::io_service io_service;
    boost::system::error_code error;

    std::deque<FileToDownload> files_to_download;
};