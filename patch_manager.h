
#include <string>

#include "downloader.h"


class PatchManager
{
public:
    void get_patch();

protected:
    void download_patch_file();
    void download_patch_contents();

protected:
    Downloader downloader;
};