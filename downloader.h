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
    void init(std::string _host, std::string _port, std::string _starting_uri_dir = "");
    void get(std::string uri, std::string expected_checksum = "", int tries = 0);
    void run();

protected:
    void remove_response_headers(std::string& response);
    bool check_file_integrity(FileToDownload& file, std::string local_file);
    std::string request_params(FileToDownload& file);
    void download(FileToDownload file);
    
public:
    std::string host, port, starting_uri_dir;
    boost::asio::io_service io_service;
    boost::system::error_code error;

    std::deque<FileToDownload> files_to_download;
};

#endif