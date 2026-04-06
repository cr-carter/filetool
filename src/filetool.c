#include <getopt.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int opt;

    while ((opt = getopt(argc, argv, ":f:a:s:r:idh")) != -1)
    {
        switch (opt)
        {
        case 'f':
            printf("Option f has arg: %s\n", optarg);
            break;
        case 'a':
            printf("Option a has arg: %s\n", optarg);
            break;
        case 's':
            printf("Option s has arg: %s\n", optarg);
            break;
        case 'r':
            printf("Option r has arg: %s\n", optarg);
            break;
        case 'i':
            printf("Option i was provided\n");
            break;
        case 'd':
            printf("Option d was provided\n");
            break;
        case 'h':
            printf("Option h was provided\n");
            break;
        case '?':
            printf("Unkown option: %c\n", optopt);
            break;
        case ':':
            printf("Missing arg for %c\n", optopt);
            break;
        }
    }

    if (optind < argc)
    {
        printf("Non-option args: ");
        while (optind < argc)
        {
            printf("%s ", argv[optind++]);
        }
        printf("\n");
    }
    return 0;
}