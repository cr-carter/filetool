/*
 * @file: getargs.h
 * @author: Chase Carter
 * @brief: Declare function in getargs.c
 */
#include "common.h"

/*
 * @brief: Provides file utility tools such as getting file info and replacing text in a file.
 *
 * @param argc: passed from main() argument
 * @param *argv[]: passed from main() argument
 * @param *arguments: struct containing program arguments for use in other functions
 *
 * @returns func_retval
 */
int getargs(int argc, char *argv[], prog_args_t *arguments);