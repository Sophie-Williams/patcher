
#include <string>


class FileToDownload
{
public:
    FileToDownload(std::string _uri, std::string _expected_checksum) 
    {
        uri = _uri;
        expected_checksum = _expected_checksum;  
    }

    std::string uri, expected_checksum;
};