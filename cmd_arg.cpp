#include "cmd_arg.h"
#include "tests.h"
#include <cstdio>
#include <cstring>
#include <cassert>

void help_cmd()
{
    printf("--test filename.txt to run unit tests\n"
           "--help to learn about flags\n"
           "input nothing to solve equation");
}

ProgramMode check_arg_cmd(int num_of_args, const char** input)
{
    assert(input);

    for (int i = 1; i < num_of_args; i++) 
    {
        const char* word = input[i];
        const char HELP_OPT[] = "--help"; 
        const char TEST_OPT[] = "--test";

        if (!strcmp(word, TEST_OPT))
        {
            if (num_of_args > ARGC_TESTS)
            {
                return ERROR_FLAG;
            }
            return TESTS_MODE;
        }

        if (!strcmp(word, HELP_OPT))
        {
            if (num_of_args > ARGC_HELP)
            {
                return ERROR_FLAG;
            }
            return HELP_MODE;
        }
    }

    if (num_of_args > ARGC_SOLVER)
    {
        return ERROR_FLAG;
    }

    return SOLVE_MODE;
}

