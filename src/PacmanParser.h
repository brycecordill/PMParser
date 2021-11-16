#ifndef PACMANPARSER_H
#define PACMANPARSER_H

#include <regex>

#include "Parser.h"

class PacmanParser : public Parser {
    public:
        void parseAndWrite();
};

#endif