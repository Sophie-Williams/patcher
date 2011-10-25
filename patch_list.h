
#include <deque>

#include "patch_file.h"


class PatchList
{
public:
    void generate_patch_files();

public:
    std::deque<PatchFile> files;

};