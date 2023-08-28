#include "tests.h"
#include "solver.h"
#include "io.h"
#include "cmd_arg.h"
#include <cstdio>
#include <cassert>

/// @brief function thats runs programm depending on chosen mode
/// @return 0 - if program worked correctly, 1 - if incorrectly
int runner(ProgramMode mode, FILE* file);

int main(int argc, char** argv) 
{
    FILE* file = nullptr;
    ProgramMode mode = check_input(argc, argv, &file);
    return runner(mode, file);
}

int runner(ProgramMode mode, FILE* file)
{  
    switch (mode)
    {
    case TESTS:
        assert(file);
        return run_all_tests(file);
    case HELP:
        help_cmd();
        return 0;
    case SOLVE:
        run_solver();
        return 0;
    default:
        printf("This case is unknown\n");
        return -1;
    }
}



