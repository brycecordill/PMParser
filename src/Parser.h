#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include "FileHandler.h"

#define GET_INPUT_LINE std::getline(*(fH->getInFile()), ln)


/* To implement later */
class Parser {
    protected:
        std::string ln;
        FileHandler *fH;
    public:
        void setFilename(char *filename);
        virtual void parseAndWrite() = 0;
        virtual ~Parser();
};

#endif