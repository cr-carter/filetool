#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/common.h"
#include "include/getargs.h"

int main(int argc, char *argv[])
{
    prog_args arguments = {0};
    getargs(argc, argv, &arguments);

    return 0;
}

/* End of file */