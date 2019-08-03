#include "ArgHandler.h"
#include "Parser.h"

int main(int argc, char **argv) {
    Parser *parser = NULL;
    char *filename = NULL;
    
    ArgHandler aH;

    parser = aH.handle(argc, argv);
    filename = argv[FILE_INDEX];
    parser->setFilename(filename);

    parser->parseAndWrite();

    delete parser;
    
    return 0;
}