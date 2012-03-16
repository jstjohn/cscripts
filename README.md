# About #
This project is a place to dump simple scripts in C and C++. Every `.c` or `.cpp` file in the `src` directory is built into a binary with the same name and placed in the `bin` directory. Each C or C++ file thus should have its own `main` function, and acts as a short script. 

# Prerequisits #
Install the Boost C++ libraries if they aren't already on your system. Also download and run `make` from the base directory of KentLib if that library isn't already on your system. KentLib may be downloaded from here [download KentLib](https://github.com/jstjohn/KentLib "KentLib").

# Installation #

0. Install all prerequisits as shown above.
1. Move your old `include.mk` file to a backup name like `include.mk.bak` if you are upgrading.
2. Execute `./setup.sh` to generate your `include.mk` file and `bin` directory.
3. Edit your `include.mk` file to point to the proper places in your system.
    3. Find out the boost libs on your system by going to the base `lib` directory where boost is installed and running a command like `ls *.a | grep boost`. Next with a program that does regex substitution get rid of all of the .a suffixes, and replace `\n^lib` with ` -l` to get names like -lboost%
4. Add the `bin` directory to your system's path.
5. Run `make` to build all of the scripts.

