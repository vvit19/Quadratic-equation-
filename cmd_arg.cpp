#include "cmd_arg.h"
#include "tests.h"
#include <cstdio>
#include <cstring>
#include <cassert>

/// @brief Flag for HELP mode
const char HELP_OPT[] = "--help"; 
/// @brief Flag for TEST mode
const char TEST_OPT[] = "--test";
/// @brief Example of file name
const char FILE_OPT[] = "filename.txt";

void help_cmd()
{
    printf("%s %s to run unit tests\n"
           "%s to learn about flags\n"
           "input nothing to solve equation", 
           TEST_OPT, FILE_OPT, HELP_OPT);
}

ProgramMode check_arg_cmd(int len, char** input)
{
    //no assert for file because it is nullptr for this time
    for (int i = 1; i < len; i++) 
    {
        char* word = input[i];
        const char* test_ptr = TEST_OPT;
        const char* help_ptr = HELP_OPT;

        if (!strcmp(word, test_ptr))
        {
            if (len > argc_tests)
            {
                return INC_FLAG;
            }
            return TESTS_MODE;
        }

        if (!strcmp(word, help_ptr))
        {
            if (len > argc_help)
            {
                return INC_FLAG;
            }
            return HELP_MODE;
        }
    }

    if (len > argc_solver)
    {
        return INC_FLAG;
    }

    return SOLVE_MODE;
}

