/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#include "IO.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

IO::IO(){

};

const std::string* IO::ReadString(std::string path)
{
    std::ifstream in(path);
    if(in) {
        std::ostringstream contents;
        contents << in.rdbuf();
        in.close();
        return contents.str();
    }
    throw std::io_errc("could not open file stream");
};