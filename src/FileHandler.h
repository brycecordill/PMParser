#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <iostream>
#include <string.h>

#define EXT ".parsed"

class FileHandler {
    private:
        std::fstream *input;
        std::fstream *output;
    public:
        FileHandler(char *inName);
        std::fstream *getOutFile() {return output;};
        std::fstream *getInFile() {return input;};
        ~FileHandler();
};

#endif