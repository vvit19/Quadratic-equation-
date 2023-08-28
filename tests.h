#ifndef TESTS_H_
#define TESTS_H_

#include <cstdio>
#include "solver.h"

/// @brief Unit tests structure (what they are consists of)
struct UnitTest {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    RootsNum roots;
};

/// @brief Runs tests
/// @param filename Name of file with tests
int run_all_tests(char* filename);

#endif