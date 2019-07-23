#include <fstream>
#include "ArgHandler.h"
#include "Parser.h"

int main(int argc, char **argv) {
    std::fstream *inFile = NULL;
    Parser *parser = NULL;
    

    ArgHandler aH;

    parser = aH.handle(argc, argv);
    inFile = aH.getInFile();

    delete parser;
    
    return 0;
}