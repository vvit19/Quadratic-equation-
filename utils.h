#ifndef UTILS_H_
#define UTILS_H_

#include <cstdio>

/// @brief Are real numbers equal
/// @param a First number
/// @param b Second number
/// @return True, if numbers are equal; false, if if they are not equal
bool is_equal(double a, double b);

/// @brief Is real number = 0
/// @param a Number
/// @return True, if a = 0; false, if a != 0
bool is_zero(double a);

/// @brief Cleans stdin buffer
void clean_buffer();

/// @brief Gets file size
/// @param file Pointer to file
/// @return File size
int get_file_size(FILE* file);

/// @brief Gets numbers of lines in file
/// @param file Pointer to file
/// @return Number of lines in file
int calc_file_nlines(FILE* file);

/// @brief Reads symbols from file to buffer (char array)
/// @param file Pointer to file
/// @param buffer_size Pointer to buffer size (function will change it to correct)
/// @return Pointer to buffer
char* get_file_content(FILE* file, int* buffer_size);

#endif