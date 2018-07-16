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

const std::string* IO::ReadString(std::string path)
{
    std::ifstream in(path);
    if(in) {
        std::ostringstream contents;
        contents << in.rdbuf();
        in.close();
        std::string* str = new std::string(contents.str());
        return str;
    }
    std::cerr << "could not open file stream";
    return nullptr;
};