#include "APTParser.h"

void APTParser::parseAndWrite() {
    while (GET_INPUT_LINE) {
        // Get to the list of newly installed packages
        if (ln.find("following NEW") != std::string::npos) {
            break;
        }
    }

    while (GET_INPUT_LINE) {
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
        unsigned long pos = ln.find_last_of('\n');
        if (pos != std::string::npos) {
            std::cout << pos << "\n";
            std::cout << ln.length() << "\n";
            ln.replace(pos, 1, " ");
        }

        // Write out the modified string
        fH->getOutFile()->write(ln.c_str(), ln.length());
    }

    // Write out a newline at the end of the file
    fH->getOutFile()->write("\n", 1);
}