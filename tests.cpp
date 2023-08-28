#include "tests.h"
#include "solver.h"
#include "utils.h"
#include "cmd_arg.h"
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>

/// @brief Solves quadratic equation with data from test
/// @return If test is correct or not
bool test_solve_quadratic(UnitTest* test);

/// @brief Runs test
void run_test(UnitTest* test, int* counter_tests, int* counter_passed_tests);

/// @brief Finds where test failed and tells this info to us
void print_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);

/// @brief Are roots written in tests equal to referenced roots
bool is_roots_equal(double x1, double x2, double x1_expected, double x2_expected);

/// @brief Check if test is correct or not
bool check_test_correct(double x1, double x1_expected, double x2, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);

/// @brief Launches tests one by one
void launch_tests(UnitTest* tests, int ntests, int* counter_tests, int* passed_tests);

/// @brief Fills array of tests with file values
/// @param tests Array of tests
/// @param ntests Number of tests
/// @param filename Name of file
UnitTest* fill_tests(int ntests, char* filename);

int run_all_tests(char* filename)
{
    assert(filename);

    int ntests = calc_file_nlines(filename);
    assert(ntests > 0);

    UnitTest* tests = fill_tests(ntests, filename);
    assert(tests);

    int counter_tests = 0;
    int passed_tests = 0;

    launch_tests(tests, ntests, &counter_tests, &passed_tests);

    printf("Tests: %d\n"
           "Passed tests: %d\n", 
           counter_tests, passed_tests);   
                 
    free(tests);
    return 0;
}

void run_test(UnitTest* test, int* counter_tests, int* counter_passed_tests) 
{
    assert(test);
    assert(counter_tests);
    assert(counter_passed_tests);

    *counter_tests += 1;
    printf("%d) ", *counter_tests);

    bool correct_test = test_solve_quadratic(test);

    if (correct_test) 
    { 
        *counter_passed_tests += 1; 
    }
}

bool test_solve_quadratic(UnitTest* test) 
{
    assert(test);

    double a = test->a;
    double b = test->b;
    double c = test->c;
    double x1_expected = test->x1;
    double x2_expected = test->x2;
    RootsNum roots_expected = test->roots;
    
    double x1 = 0;
    double x2 = 0;
    RootsNum roots = solve_quadratic(a, b, c, &x1, &x2);

    return check_test_correct(x1, x1_expected, x2, x2_expected, roots, roots_expected);
}

bool check_test_correct(double x1, double x1_expected, double x2, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected)
{
    if (is_roots_equal(x1, x2, x1_expected, x2_expected) && roots == roots_expected)
    {
        printf("All right\n");
        return true;
    }

    print_test_fail(x1, x2, x1_expected, x2_expected, roots, roots_expected);
    return false;
}

void print_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected)
{
    printf("Test failed\n");

    if (!is_equal(x1, x1_expected))
    {
        printf("x1 = %f != x1_expected = %f\n", x1, x1_expected);
    }

    if (!is_equal(x2, x2_expected))
    {
        printf("x2 = %f != x2_expected = %f\n", x2, x2_expected);
    }

    if (!is_equal(roots, roots_expected))
    {
        printf("Number of roots != Expected number of roots\n");
    }
}

bool is_roots_equal(double x1, double x2, double x1_expected, double x2_expected) 
{
    return ((is_equal(x1, x1_expected) && is_equal(x2, x2_expected)) || 
            (is_equal(x2, x1_expected) && is_equal(x1, x2_expected)));
}

void launch_tests(UnitTest* tests, int ntests, int* counter_tests, int* passed_tests)
{
    assert(tests);
    assert(counter_tests);
    assert(passed_tests);

    for (int i = 0; i < ntests; i++) 
    {
        run_test(tests + i, counter_tests, passed_tests);
    }
}

UnitTest* fill_tests(int ntests, char* filename)
{
    assert(filename);

    UnitTest* tests = (UnitTest*) calloc(ntests, sizeof(UnitTest));
    assert(tests);

    FILE* file = fopen(filename, "r");
    if (file == nullptr)
    {
        return nullptr;
    }

    char* buffer = get_file_content(file);
    if (buffer == nullptr)
    {
        fclose(file);
        free(tests);
        return nullptr;
    }

    int* lines_sizes = get_lines_sizes(ntests, file, buffer);
    if (lines_sizes == nullptr)
    {
        fclose(file);
        free(tests);
        free(buffer);
        return nullptr;
    }

    int shift = 0;
    for (int i = 0; i < ntests; i++)
    {
        sscanf((buffer + shift), 
              "%lf %lf %lf %lf %lf %d",
              &((tests + i)->a),
              &((tests + i)->b),
              &((tests + i)->c),
              &((tests + i)->x1),
              &((tests + i)->x2),
              (int*)&((tests + i)->roots));

        shift += lines_sizes[i];
    }

    fclose(file);
    free(tests);
    free(buffer);

    return tests;
}