#include "cmd_arg.h"
#include "tests.h"
#include <cstdio>
#include <cstring>

void help_cmd();
void test_cmd();

void help_cmd()
{
    printf("Write %s to run unit tests\n"
           "Write %s to learn about flags\n"
           "Write nothing to solve equation", 
           TEST_OPT, HELP_OPT);
}

void test_cmd()
{
    run_all_tests();
}

bool check_input(int len, char** input)
{
    for (int i = 1; i < len; i++) 
    {
        char* word = input[i];
        const char* test_ptr = TEST_OPT;
        const char* help_ptr = HELP_OPT;

        if (!strcmp(word, test_ptr))
        {
            test_cmd();
            return true;
        }

        if (!strcmp(word, help_ptr))
        {
            help_cmd();
            return true;
        }
    }
    return false;
}

