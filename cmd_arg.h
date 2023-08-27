#ifndef COMM_ARG_H_
#define CMD_ARG_H_

#include <cstdio>

enum ProgrammMode {
    TESTS, 
    HELP, 
    SOLVE
};

const char HELP_OPT[] = "--help";
const char TEST_OPT[] = "--test";
const char FILE_OPT[] = "filename.txt";

ProgrammMode check_input(int len, char **input, FILE** file);
int help_cmd();

#endif