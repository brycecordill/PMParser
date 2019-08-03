#include "ArgHandler.h"

void ArgHandler::printUsage() {
    std::cout << "Usage: pmparser [PACKAGE_MANAGER] [FILE]\n\n";
    std::cout << "Valid package managers: dnf\n";
    exit(EXIT_FAILURE);
}

Parser *ArgHandler::handle(int argc, char **argv) {
    Parser *p = NULL;

    if (argc != NUM_ARGS) {
        printUsage();
    }

    p = tryPM(argv[PM_INDEX]);

    return p;
}

// TODO Implement with correct subtypes
Parser *ArgHandler::tryPM(char *pm) {
    if (strcmp(pm, "dnf") == 0 || strcmp(pm, "yum") == 0) {
        return new DNFParser;
    }

    printUsage();
    return NULL;
}