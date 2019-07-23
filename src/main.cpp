#include <fstream>
#include "argHandler.h"
#include "parser.h"

int main(int argc, char **argv) {
    std::fstream *inFile = NULL;
    parser *pmParser = NULL;
    

    argHandler a;

    pmParser = a.handle(argc, argv);
    inFile = a.getInFile();

    delete pmParser;
    
    return 0;
}