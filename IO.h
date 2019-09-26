/*
 * Created by Maximiliano Levi on 12/07/2018.
 */

#ifndef GLRAYTRACING_IO_H
#define GLRAYTRACING_IO_H

#include <string>

class IO {
public:
    static const char* IO::ReadString(const char* path);

private:
    IO();
};


#endif //GLRAYTRACING_IO_H
