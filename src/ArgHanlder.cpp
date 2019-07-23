#include "ArgHandler.h"

ArgHandler::ArgHandler() {
    inFile = NULL;
}

void ArgHandler::printUsage() {
    std::cout << "Usage: pmparser [PACKAGE_MANAGER] [FILE]\n\n";
    std::cout << "Valid package managers: apt, dnf, pacman\n";
    exit(EXIT_FAILURE);
}

Parser *ArgHandler::handle(int argc, char **argv) {
    Parser *p = NULL;

    if (argc != NUM_ARGS) {
        printUsage();
    }

    p = tryPM(argv[PM_INDEX]);

    inFile = new std::fstream(argv[FILE_INDEX], std::ios::in);
    if (inFile->bad() || inFile->fail()) {
        std::cerr << "Unable to open file " << argv[FILE_INDEX] << "\n";
        exit(EXIT_FAILURE);
    }

    return p;
}

// TODO Implement with correct subtypes
Parser *ArgHandler::tryPM(char *pm) {
    if (strcmp(pm, "dnf") == 0 || strcmp(pm, "yum") == 0) {
        return new Parser();
    }
    else if(strcmp(pm, "apt") == 0 || strcmp(pm, "apt-get") == 0) {
        return new Parser();
    }
    else if (strcmp(pm, "pacman") == 0) {
        return new Parser();
    }
    std::cout << "Here\n";
    printUsage();
    return NULL;
}

ArgHandler::~ArgHandler() {
    if (inFile != NULL) {
        inFile->close();
        delete inFile;
    }
}