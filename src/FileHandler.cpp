#include "FileHandler.h"

FileHandler::FileHandler(char *fname) {
    input = new std::fstream(fname, std::ios::in);

    if (input->bad() || input->fail()) {
        std::cout << "Failed to open " << fname << "\n";
        input = NULL;
        output = NULL;
        exit(EXIT_FAILURE);
    }

    char *outName = new char[strlen(fname) + strlen(EXT) + 1];
    strcpy(outName, fname);
    strcat(outName, EXT);
    
    output = new std::fstream(outName, std::ios::out);

    if (output->bad() || output->fail()) {
        std::cout << "Failed to create or open " << outName << "\n";
        output = NULL;
        exit(EXIT_FAILURE);
    }

    delete outName;
}

FileHandler::~FileHandler() {
    if (input != NULL) {
        input->close();
        delete input;
    }

    if (output != NULL) {
        output->close();
        delete output;
    }
}