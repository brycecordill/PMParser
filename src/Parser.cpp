#include "Parser.h"

void Parser::setFilename(char *filename) {
    fH = new FileHandler(filename);
}

Parser::~Parser() {
    if (fH != NULL) {
        delete fH;
    }
}