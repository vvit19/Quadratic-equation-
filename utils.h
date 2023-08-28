#ifndef UTILS_H_
#define UTILS_H_

#include <cstdio>

/// @brief Are double numbers equal
/// @param a First number
/// @param b Second number
/// @return If a = b or not
bool is_equal(double a, double b);

/// @brief Is double number = 0
/// @param a Number
/// @return If a = 0 or not
bool is_zero(double a);

/// @brief Cleans stdin buffer
void clean_buffer();

/// @brief Gets file size
int get_file_size(FILE* file);

/// @brief Reads symbols from file to buffer
/// @return File_size (it is not similar with value from get_file_size() \
            fread and ftell work a little bit different with txt files)
int read_file(FILE* file, char* buffer, int max_file_size);

/**
 * Reads char array (we can imagine it like text) and returns number of lines in text \
 * (they are divided in array by '\n')
*/
int calc_nlines(char* array, int array_size);

/// @brief Assign pointer to filename.txt to returns it
FILE* read_filename(char* filename);

/// @brief Gets numbers of lines from file
int get_file_nlines(char* filename);

/// @brief Gets numbers of lines from text (char array)
int get_text_nlines(FILE* file);

/// @brief Gets size of buffer (any char array)
int get_buffer_size(FILE* file, char* buffer);

char* fill_buffer(FILE* file);

int* get_lines_sizes(int ntests, FILE* file, char* buffer);

#endif