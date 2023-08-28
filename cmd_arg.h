#ifndef CMD_ARG_H_
#define CMD_ARG_H_

#include <cstdio>

/// @brief definition of enum that holds program modes
enum ProgramMode {
    TESTS, ///<if user wants to run tests
    SOLVE, ///<if user wants to solve equation 
    HELP   ///<if user needs help 
};

/// @brief check, what user've input in cmd to choose program mode
/// @param len amount of inputed words
/// @param input array of inputed words
/// @param file pointer to file (for tests)
/// @return program mode
ProgramMode check_input(int len, char **input, FILE** file);

/// @brief prints info (in help mode)
/// @return result of program implementation (GIVE_INFO)
void help_cmd();

#endif