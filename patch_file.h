
#include <string>


class PatchFile
{
public:
    PatchFile(std::string _uri, std::string _checksum) 
    {
        uri = _uri;
        checksum = _checksum; 
    }

    std::string string() {
        return uri + " " + checksum;
    }

    std::string uri, checksum;
};