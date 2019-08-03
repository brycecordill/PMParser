#include "APTParser.h"

void APTParser::parseAndWrite() {
    while (std::getline(*(fH->getInFile()), ln)) {
        // Get to the list of newly installed packages
        if (ln.find("following NEW") != std::string::npos) {
            break;
        }

        while (std::getline(*(fH->getInFile()), ln)) {
            if (fH->getInFile()->eof()) {
                break;
            }
            // If the line isn't indented (no longer in package list)
            else if (ln.front() != ' ') {
                break;
            }

            // Remove the first space
            ln.erase(ln.begin());
            // Replace the last char (\n) with a space
            ln.replace(ln.length() - 1, 1, " ");

            // Write out the modified string
            fH->getOutFile()->write(ln.c_str(), ln.length());
        }
    }
}