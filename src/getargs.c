#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/common.h"

int getargs(int argc, char *argv[], prog_args *arguments)
{
    int func_retval = 0;
    int opt;

    static struct option long_options[] = {
        {"filename", required_argument, 0, 'f'}, {"append", required_argument, 0, 'a'},
        {"search", required_argument, 0, 's'},   {"replace", required_argument, 0, 'r'},
        {"info", no_argument, 0, 'i'},           {"delete", no_argument, 0, 'd'},
        {"help", no_argument, 0, 'h'},           {0, 0, 0, 0}};

    while ((opt = getopt_long(argc, argv, "-:f:a:s:r:idh", long_options, NULL)) != -1)
    {
        if (opt == -1)
            break;

        switch (opt)
        {
        case 'f':
            arguments->filename = optarg;
            break;
        case 'a':
            arguments->append = optarg;
            break;
        case 's':
            arguments->search = optarg;
            break;
        case 'r':
            arguments->replace = optarg;
            break;
        case 'i':
            arguments->is_info = true;
            break;
        case 'd':
            arguments->is_delete = true;
            break;
        case 'h':
            arguments->is_help = true;
            break;
        case '?':
            func_retval = -1;
            break;
        }
    }

    return func_retval;
}

/* End of file */