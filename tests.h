#ifndef TESTS_H_
#define TESTS_H_

#include <cstdio>
#include "solver.h"

enum IsTestsPassed {
    TESTS_OK = 0, ///tests runned successfully
    TESTS_ERROR = 1 ///tests runned with an error
};

/// @brief Unit tests structure (what they are consists of)
struct UnitTest {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    RootsNum roots;
};

/// @brief runs tests
/// @param file file with tests
/// @return if tests passed or not
int run_all_tests(FILE* file);

#endif