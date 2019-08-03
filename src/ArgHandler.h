#ifndef ARGHANDLER_H
#define ARGHANDLER_H

#include <iostream>
#include <string.h>
#include "Parser.h"
#include "DNFParser.h"

#define NUM_ARGS 3
#define PM_INDEX 1
#define FILE_INDEX 2

class ArgHandler{
    private:
        void printUsage();
        Parser *tryPM(char *pm);
    public:
        Parser *handle(int argc, char **argv);
};

#endif