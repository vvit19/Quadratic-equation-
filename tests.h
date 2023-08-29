#ifndef TESTS_H_
#define TESTS_H_

#include "solver.h"

/// @brief Unit tests structure (what they are consists of)
struct UnitTest {
    double a;       ///< Coefficient a
    double b;       ///< Coefficient a
    double c;       ///< Coefficient a
    double x1;      ///< Coefficient a
    double x2;      ///< Coefficient a
    RootsNum roots; ///< Number of roots
};

/// @brief Runs tests
/// @param filename Name of file with tests
/// @return 0, if tests've runned correctly, exit_code - if incorrectly 
int run_all_tests(char* filename);

#endif