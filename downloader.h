#ifndef __DOWNLOADER__
#define __DOWNLOADER__

#include <string>
#include <iostream>
#include <sstream>
#include <deque>
#include <boost/asio.hpp>

#include "file_manager.h"
#include "file_to_download.h"

using boost::asio::ip::tcp;

#define MAX_TRIES     5


class Downloader 
{
public:
    void init(std::string _host, std::string _port);
    void get(std::string uri, std::string expected_checksum = "", int tries = 0);
    void run();

protected:
    void _download(FileToDownload file);
    
public:
    std::string host, port;
    boost::asio::io_service io_service;
    boost::system::error_code error;

    std::deque<FileToDownload> files_to_download;
};

#endif