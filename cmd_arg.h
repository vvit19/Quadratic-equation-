#ifndef CMD_ARG_H_
#define CMD_ARG_H_

/// @brief Definition of enum that holds program modes
enum ProgramMode {
    TESTS_MODE, ///<If user wants to run tests
    SOLVE_MODE, ///<If user wants to solve equation 
    HELP_MODE,  ///<If user needs help 
    ERROR_FLAG  ///<If user inputs incorrect flag
};

/// @brief Check, what user've input in cmd to choose program mode
/// @param num_of_args Amount of inputed words
/// @param input Array of inputed words
/// @return Program mode
ProgramMode check_arg_cmd(int num_of_args, char **input);

/// @brief Number of cmd arguments in solve mode
const int ARGC_SOLVER = 1;
/// @brief Number of cmd arguments in help mode
const int ARGC_HELP = 2;
/// @brief Number of cmd arguments in tests mode
const int ARGC_TESTS = 3;

/// @brief Prints info (in help mode)
void help_cmd();

#endif