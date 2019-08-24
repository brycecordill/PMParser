#include "FileHandler.h"

FileHandler::FileHandler(char *fname) {
    input = new std::fstream(fname, std::ios::in);

    if (input->bad() || input->fail()) {
        std::cerr << "Failed to open " << fname << "\n";
        input = NULL;
        output = NULL;
        exit(EXIT_FAILURE);
    }

    std::string outName(fname);
    outName.append(EXT);
    
    output = new std::fstream(outName, std::ios::out);

    if (output->bad() || output->fail()) {
        std::cerr << "Failed to create or open " << outName << "\n";
        output = NULL;
        exit(EXIT_FAILURE);
    }
}

FileHandler::~FileHandler() {
    if (input->is_open()) {
        input->close();
        delete input;
    }

    if (output->is_open()) {
        output->close();
        delete output;
    }
}