
#include <string>


class FileToDownload
{
public:
    FileToDownload(std::string _uri, std::string _expected_checksum, int _tries = 0) 
    {
        uri = _uri;
        expected_checksum = _expected_checksum; 
        tries = _tries;
    }

    std::string uri, expected_checksum;
    int tries;
};