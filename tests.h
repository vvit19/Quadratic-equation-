#ifndef TESTS_H_
#define TESTS_H_

#include <cstdio>
#include "solver.h"

enum Tests_Result {
    TESTS_OK = 0, ///<Tests runned successfully
    TESTS_ERROR = 1 ///<Tests runned with an error
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

/// @brief Runs tests
/// @param file File with tests
/// @return If tests passed or not
Tests_Result run_all_tests(char* filename);

#endif