#ifndef IO_H_
#define IO_H_

#include "solver.h"

/// @brief Reads equation coefficient
/// @param coeff Pointer to coefficient
/// @param ch Symbol, denoting coefficient
void read_coeff(double* coeff, char ch);

/// @brief Outputs equation solutions
/// @param roots Amount of roots
/// @param x_1 First root 
/// @param x_2 Second root
void output_solutions(RootsNum roots, double x_1, double x_2);

#endif