#ifndef COMM_LINE_ARG_H_
#define COMM_LINE_ARG_H_
#define HELP "--help"
#define TEST "--test"

bool check_input(int len, char **input, char const* text);
void help_cmd();
void test_cmd();

#endif