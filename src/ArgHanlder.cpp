#include "ArgHandler.h"

void ArgHandler::printUsage() {
    std::cerr << "Usage: pmparser [PACKAGE_MANAGER] [FILE]\n\n";
    std::cerr << "Valid package managers: apt, dnf, zypper, pacman\n";
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

Parser *ArgHandler::tryPM(char *pm) {
    if (strcmp(pm, "dnf") == 0 || strcmp(pm, "yum") == 0) {
        return new DNFParser;
    }
    else if (strcmp(pm, "apt") == 0 || strcmp(pm, "apt-get") == 0) {
        return new APTParser;
    }
    else if (strcmp(pm, "zypper") == 0) {
        return new ZypperParser;
    }
    else if (strcmp(pm, "pacman") == 0) {
        return new PacmanParser;
    }

    printUsage();
    return NULL;  // Makes the compiler happy
}