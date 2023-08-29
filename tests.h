#ifndef TESTS_H_
#define TESTS_H_

#include "solver.h"

/// @brief Unit tests structure (what they are consists of)
struct UnitTest {
    double a;       ///< Coefficient a
    double b;       ///< Coefficient b
    double c;       ///< Coefficient c
    double x1;      ///< First root
    double x2;      ///< Second root
    RootsNum roots; ///< Number of roots
};

/// @brief Runs tests
/// @param filename Name of file with tests
/// @return 0, if tests've runned correctly, exit_code - if incorrectly 
int run_all_tests(char* filename);

#endif