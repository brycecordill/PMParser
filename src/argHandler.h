#ifndef ARGHANDLER_H
#define ARGHANDLER_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "parser.h"

#define NUM_ARGS 3
#define PM_INDEX 1
#define FILE_INDEX 2

class argHandler{
    private:
        std::fstream *inFile;
        
        void printUsage();
        parser *tryPM(char *pm);
    public:
        argHandler();
        parser *handle(int argc, char **argv);
        std::fstream *getInFile() {return inFile;};
        ~argHandler();
};

#endif