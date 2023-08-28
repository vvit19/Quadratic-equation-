#include "tests.h"
#include "solver.h"
#include "io.h"
#include "cmd_arg.h"
#include <cstdio>
#include <cassert>

/// @brief Function thats runs programm depending on chosen mode
/// @return 0 - if program worked correctly, -1 - if incorrectly
int runner(ProgramMode mode, char** argv);

int main(int argc, char** argv) 
{
    ProgramMode mode = check_arg_cmd(argc, argv);
    int exit_code = runner(mode, argv);
    return exit_code;
}

int runner(ProgramMode mode, char** argv)
{  
    switch (mode)
    {
    case TESTS_MODE:
        return run_all_tests(argv[argc_tests - 1]);
    case HELP_MODE:
        help_cmd();
        return 0;
    case SOLVE_MODE:
        run_solver();
        return 0;
    case INC_FLAG:
        printf("Incorrect flag input!\n");
        return -1;
    default:
        printf("This case is unknown\n");
        return -1;
    }
}



