# PMParser
A program that takes the output from Linux package managers and parses them so they are all on one line.  This is useful when installing a large package group (like a desktop enviornment) and you want to make sure that you can easily remove all newly installed packages later.

All you need to do is copy or pipe the output of a package manager's install command into a file, run this program with the file, and then copy and paste the contents of the ```.parsed``` file into the package manager's remove command to remove the packages.

# Dependencies
In order to compile this program, you'll need the c++ compiler ```g++```, which can be found in your Linux distro's repository.

# Compiling
First, clone the repo: 
```
$ git clone https://github.com/brycecordill/PMParser.git
```

Next, cd into the ```src/``` directory and compile the project:
```
$ cd PMParser/src/ && make
```

# Installing/Uninstalling
If you'd like to install the program system-wide, simply run the command
```
sudo make install
```
If you'd like to uninstall this program, run
```
sudo make uninstall
```
in the ```src/``` directory

# Usage
To run the program, make sure you are still in the ```src/``` directory.  You can then run the program to make sure everything is ready:
```
$ ./pmparser
```
This should print a usage/help message on screen.

To parse a file, use this pattern:
```
$ ./pmparser PACKAGE_MANAGER PATH_TO_FILE
```

The output will be saved in the same directory as the input file, but with a ```.parsed``` extension.  Sample input and output files are located in the ```samples/``` directory.
