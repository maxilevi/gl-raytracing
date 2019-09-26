/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "IO.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

IO::IO(){

};

const char* IO::ReadString(const char* path)
{
    std::ifstream in(path);
    if(in) {
        std::ostringstream contents;
        contents << in.rdbuf();
        in.close();
        return contents.str().c_str();
    }
    std::cerr << "could not open file stream";
    return NULL;
};