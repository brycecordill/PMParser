#ifndef APTPARSER_H
#define APTPARSER_H

#include "Parser.h"

class APTParser : public Parser {
    public:
        void parseAndWrite();
};

#endif