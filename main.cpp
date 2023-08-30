#include "tests.h"
#include "solver.h"
#include "io.h"
#include "cmd_arg.h"
#include <cstdio>
#include <cassert>

/// @brief Function thats runs programm depending on chosen mode
/// @return 0 - if program worked correctly, error code - if incorrectly

int main(int argc, const char** argv) 
{
    ProgramMode mode = check_arg_cmd(argc, argv);    
    const char* filename = argv[ARGC_TESTS - 1];

    switch (mode)
    {
    case TESTS_MODE: {
        int res_tests = run_all_tests(filename); 
        return res_tests;
    }     

    case HELP_MODE: 
        help_cmd();
        return 0;

    case SOLVE_MODE: 
        run_solver();
        return 0;

    case ERROR_FLAG: 
        printf("Incorrect flag input!\n");
        return -1;
       
    default:
        printf("Default case reached in file: " 
               __FILE__
               "\nIn line: %d", 
               __LINE__);
        return -1;
    }    
}
