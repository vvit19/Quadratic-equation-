#ifndef IO_H_
#define IO_H_

#include "solver.h"

/// @brief reads equation coefficient
/// @param coeff pointer to coefficient
/// @param ch symbol, denoting coefficient
void read_coeff(double* coeff, char ch);

/// @brief outputs equation solutions
/// @param roots amount of roots
/// @param x_1 first root 
/// @param x_2 second root
void output_solutions(RootsNum roots, double x_1, double x_2);

#endif