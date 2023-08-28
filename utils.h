#ifndef UTILS_H_
#define UTILS_H_

#include <cstdio>

/// @brief are double numbers equal
/// @param a first number
/// @param b second number
/// @return if a = b or not
bool is_equal(double a, double b);

/// @brief is double number = 0
/// @param a number
/// @return if a = 0 or not
bool is_zero(double a);

/// @brief cleans stdin buffer
void clean_buffer();

/// @brief gets file size
int get_file_size(FILE* file);

/// @brief reads symbols from file to buffer
/// @return file_size (it is not similar with value from get_file_size() because fread and ftell \
                       work a little bit different with txt files)
int read_file(FILE* file, char* buffer, int max_file_size);

/**
 * reads symbols from buffer and brings to array symb_in_line amount of symbols per line
 * (lines are divided by '\n')
*/
void get_line_size(int* symb_in_line, int file_size, char* buffer);

/**
 * reads char array (we can imagine it like text) and returns number of lines in text \
 * (they are divided in array by '\n')
*/
int calc_nlines(char* array, int array_size);

#endif