#include "tests.h"
#include "solver.h"
#include "utils.h"
#include "cmd_arg.h"
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>

/// @brief Run unit test
/// @param test Pointer to test structure
/// @param tests_count Counter of tests
/// @param passed_tests_count Counter of passed tests 
static void run_test(UnitTest* test, int* tests_count, int* passed_tests_count);

/// @brief Finds where test failed and tells this info to us
/// @param x1 First root received from program
/// @param x2 Second root received from program
/// @param x1_expected First root received from file with tests
/// @param x2_expected Second root received from file with tests
/// @param roots Number of roots recieved from program
/// @param roots_expected Number of roots recieved from file with tests
static void print_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);

/// @brief Creates array of tests and fills it with data from file with tests
/// @param ntests Number of tests
/// @param file Pointer to file with tests
/// @return Pointer to array with tests
static UnitTest* read_file_tests(int ntests, FILE* file);

/// @brief Are roots written in tests equal to referenced roots
/// @param x1 First root received from program
/// @param x2 Second root received from program
/// @param x1_expected First root received from file with tests
/// @param x2_expected Second root received from file with tests
/// @return If they are equal or not
static bool is_roots_equal(double x1, double x2, double x1_expected, double x2_expected);

/// @brief This enum holds tests errors
enum ERRORS {
    FILE_NOT_FOUND   = -2, ///<If file haven't been founded
    MEM_ALLOC_ERROR = -1,  ///<If OS didn't give memory (when calloc returns nullptr)
}; 

int run_all_tests(char* filename)
{
    assert(filename);

    FILE* file = fopen(filename, "r");  
    if (file == nullptr)
    {
        return FILE_NOT_FOUND;
    }

    int ntests = calc_file_nlines(file);
    if (ntests < 0)
    {
        return MEM_ALLOC_ERROR;
    }

    UnitTest* tests = read_file_tests(ntests, file);
    if (tests == nullptr)
    {
        return MEM_ALLOC_ERROR;
    }

    int tests_count = 0;
    int passed_tests = 0;
    for (int i = 0; i < ntests; i++) 
    {
        run_test(tests + i, &tests_count, &passed_tests);
    }

    printf("Tests: %d\n"
           "Passed tests: %d\n", 
           tests_count, 
           passed_tests);   
                 
    free(tests);
    return 0;
}

static void run_test(UnitTest* test, int* tests_count, int* passed_tests_count) 
{
    assert(test);
    assert(tests_count);
    assert(passed_tests_count);

    *tests_count += 1;
    printf("%d) ", *tests_count);

    double a = test->a;
    double b = test->b;
    double c = test->c;
    double x1_expected = test->x1;
    double x2_expected = test->x2;
    RootsNum roots_expected = test->roots;

    double x1 = 0;
    double x2 = 0;
    RootsNum roots = solve_quadratic(a, b, c, &x1, &x2);
//оставил без сорта из-за проблемы при одном корне, тогда делать так быстрее
    if (is_roots_equal(x1, x2, x1_expected, x2_expected) && roots == roots_expected)
    {
        printf("All right\n");
        *passed_tests_count += 1;
    }
    else
    {
        print_test_fail(x1, x2, x1_expected, x2_expected, roots, roots_expected);
    }
}

static void print_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
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

static UnitTest* read_file_tests(int ntests, FILE* file)
{
    assert(file);

    UnitTest* tests = (UnitTest*) calloc(ntests, sizeof(UnitTest));
    if (tests == nullptr)
    {
        return nullptr;
    }

    int buffer_size = 0;
    char* buffer = get_file_content(file, &buffer_size);

    if (buffer == nullptr)
    {
        fclose(file);
        free(tests);
        return nullptr;
    }

    int shift = 0;
    for (int i = 0; i < ntests; i++)
    {
        sscanf((buffer + shift), 
              "%lf %lf %lf %lf %lf %d",
              &(tests[i].a),
              &(tests[i].b),
              &(tests[i].c),
              &(tests[i].x1),
              &(tests[i].x2),
              (int*)&(tests[i].roots));

        shift++;
        while (buffer[shift] != '\n')
        {
            shift++;
        }
    }

    free(buffer);
    return tests;
}

static bool is_roots_equal(double x1, double x2, double x1_expected, double x2_expected) 
{
    return ((is_equal(x1, x1_expected) && is_equal(x2, x2_expected)) || 
            (is_equal(x2, x1_expected) && is_equal(x1, x2_expected)));
}