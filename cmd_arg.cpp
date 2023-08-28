#include "cmd_arg.h"
#include "tests.h"
#include <cstdio>
#include <cstring>
#include <cassert>

/// @brief Flag for HELP mode
const char HELP_OPT[] = "--help"; 
/// @brief Flag for TEST mode
const char TEST_OPT[] = "--test";

void help_cmd()
{
    printf("%s filename.txt to run unit tests\n"
           "%s to learn about flags\n"
           "input nothing to solve equation", 
           TEST_OPT, HELP_OPT);
}

ProgramMode check_arg_cmd(int len, char** input)
{
    assert(input);

    for (int i = 1; i < len; i++) 
    {
        char* word = input[i];
        const char* test_ptr = TEST_OPT;
        const char* help_ptr = HELP_OPT;

        if (!strcmp(word, test_ptr))
        {
            if (len > ARGC_TESTS)
            {
                return INC_FLAG;
            }
            return TESTS_MODE;
        }

        if (!strcmp(word, help_ptr))
        {
            if (len > ARGC_HELP)
            {
                return INC_FLAG;
            }
            return HELP_MODE;
        }
    }

    if (len > ARGC_SOLVER)
    {
        return INC_FLAG;
    }

    return SOLVE_MODE;
}

