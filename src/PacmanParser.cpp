#include "PacmanParser.h"

void PacmanParser::parseAndWrite() {
    while (GET_INPUT_LINE) {
        // Get to the list of newly installed packages
        if (ln.find("Packages (") != std::string::npos) {
            // Remove "Packages (\d)"
            ln = ln.substr(ln.find_last_of(')') + 1);
            break;
        }
    }

    // Regex for package version numbers
    std::regex re(R"(-\d\S* *)");

    // Do-while so it doesn't skip the first line
    do {
        if (fH->getInFile()->eof()) {
            break;
        }
        // If the line isn't indented (no longer in package list)
        else if (!isspace(ln.front())) {
            break;
        }

        // Remove the first spaces
        ln.erase(0, ln.find_first_not_of(' '));
        // Replace the last char (\n) with a space
        ln.replace(ln.length(), 1, " ");

        //Remove version numbers and duplicate spaces
        ln = std::regex_replace(ln, re, " ");

        // Write out the modified string
        fH->getOutFile()->write(ln.c_str(), ln.length());

    } while (GET_INPUT_LINE);

    // Write out a newline at the end of the file
    fH->getOutFile()->write("\n", 1);
}