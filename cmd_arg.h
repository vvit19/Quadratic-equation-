#ifndef CMD_ARG_H_
#define CMD_ARG_H_

#include <cstdio>

/// @brief Definition of enum that holds program modes
enum ProgramMode {
    TESTS_MODE, ///<If user wants to run tests
    SOLVE_MODE, ///<If user wants to solve equation 
    HELP_MODE,  ///<If user needs help 
    INC_FLAG    ///<If user inputs incorrect flag
};

/// @brief Check, what user've input in cmd to choose program mode
/// @param len Amount of inputed words
/// @param input Array of inputed words
/// @return Program mode
ProgramMode check_arg_cmd(int len, char **input);

/// @brief Number of cmd arguments in solve mode
const int argc_solver = 1;
/// @brief Number of cmd arguments in help mode
const int argc_help = 2;
/// @brief Number of cmd arguments in tests mode
const int argc_tests = 3;

/// @brief Prints info (in help mode)
void help_cmd();

#endif