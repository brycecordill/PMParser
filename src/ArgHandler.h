#ifndef ARGHANDLER_H
#define ARGHANDLER_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "Parser.h"

#define NUM_ARGS 3
#define PM_INDEX 1
#define FILE_INDEX 2

class ArgHandler{
    private:
        std::fstream *inFile;
        
        void printUsage();
        Parser *tryPM(char *pm);
    public:
        ArgHandler();
        Parser *handle(int argc, char **argv);
        std::fstream *getInFile() {return inFile;};
        ~ArgHandler();
};

#endif