#ifndef DNFPARSER_H
#define DNFPARSER_H

#include "Parser.h"

class DNFParser : public Parser {
    public:
        void parseAndWrite();
};

#endif