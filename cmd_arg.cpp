#include "cmd_arg.h"
#include "tests.h"
#include <cstdio>
#include <cstring>
#include <cassert>

void input_filename(FILE** file, char* filename);

int help_cmd()
{
    printf("%s %s to run unit tests\n"
           "%s to learn about flags\n"
           "input nothing to solve equation", 
           TEST_OPT, FILE_OPT, HELP_OPT);

    return GIVE_INFO;
}

ProgrammMode check_input(int len, char** input, FILE** file)
{
    //no assert for file because it is nullptr for this time
    for (int i = 1; i < len; i++) 
    {
        char* word = input[i];
        const char* test_ptr = TEST_OPT;
        const char* help_ptr = HELP_OPT;

        if (!strcmp(word, test_ptr))
        {
            input_filename(file, input[i + 1]);
            return TESTS;
        }

        if (!strcmp(word, help_ptr))
        {
            return HELP;
        }
    }

    return SOLVE;
}

void input_filename(FILE** file, char* filename)
{
    //no assert for file because it is nullptr for this time
    *file = fopen(filename, "r");
}

