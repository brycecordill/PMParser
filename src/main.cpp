#include "argHandler.h"
#include "parser.h"

int main(int argc, char **argv) {

    argHandler a;

    a.handle(argc, argv);

    return 0;
}