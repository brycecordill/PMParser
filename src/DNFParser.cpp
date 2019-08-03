#include "DNFParser.h"

void DNFParser::parseAndWrite() {
    // Get to the package list
    while (GET_INPUT_LINE) {
        if (ln.find("Installing") != std::string::npos) {
            break;
        }
    }

    while (GET_INPUT_LINE) {
        if (fH->getInFile()->eof()) {
            break;
        }
        else if (ln.find("Installing") != std::string::npos) {
            continue;
        }
        // If it's a heading which doesn't include "Installing"
        else if (ln.front() != ' ') {
            break;
        }
        
        // Remove the first space
        ln.erase(ln.begin());
        // Remove everything after the first word and a space
        ln.erase(ln.find_first_of(' ') + 1);

        // Write the resulting string
        fH->getOutFile()->write(ln.c_str(), ln.length());
    }

    // Write out a newline at the end of the file
    fH->getOutFile()->write("\n", 1);
}