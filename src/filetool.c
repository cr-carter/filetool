#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/getargs.h"

typedef struct prog_args_t
{
    char *filename;
    bool is_filename;
    char *append;
    bool is_append;
    char *search;
    bool is_search;
    char *replace;
    bool is_replace;
    bool is_info;
    bool is_delete;
    bool is_help;
} prog_args;

int main(int argc, char *argv[])
{
    prog_args arguments = {0};
    getargs(argc, argv);

    return 0;
}