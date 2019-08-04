# PMParser
A program that takes the output from Linux package managers and parses them so they are all on one line.  This is useful when installing a large package group (like a desktop enviornment) and you want to make sure that you can easily remove all newly installed packages later.

# Compiling
First, clone the repo: 
```$ git clone https://github.com/brycecordill/PMParser.git```

Next, cd into the ```src/`` directory and compile the project:
```$ cd PMParser/src/ && make```

Future versions will support the ```make install``` command

# Usage
To run the program, make sure you are still in the ```src/``` directory.  You can then run the program to make sure everything is ready:
```$ ./pmparser```
This will print a usage/help message on screen.

To parse a file, use this pattern:
```$ ./pmparser PACKAGE_MANAGER PATH_TO_FILE```

The output will be saved in the same directory as the input file, but with a ```.parsed``` extension.  Sample input and output files are located in the ```samples/``` directory.