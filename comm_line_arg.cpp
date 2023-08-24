#include "comm_line_arg.h"
#include "tests.h"
#include <cstdio>

void help_cmd()
{
    printf("Write %s to run unit tests\n"
           "Write %s to learn about flags\n"
           "Write nothing to solve equation", TEST, HELP);
}

void test_cmd()
{
    run_all_tests();
}

bool check_input(int len, char **input, char const* text)
{
    for (int i = 1; i < len; i++) 
    {
        char* ptr_input = input[i];
        char const* ptr_text = text;

        for (int j = 0; *ptr_input++ == *ptr_text++; j++)
        {
            if (*ptr_input == '\0') 
            {
                return true;
            }
        }
    }
    
    return false;
}

