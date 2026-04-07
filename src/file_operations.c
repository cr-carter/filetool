#define _POSIX_C_SOURCE 200809L

#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "include/file_operations.h"

int file_search(void)
{
    printf("Searched file\n");
    return 0;
}

int file_replace(void)
{
    printf("Replaced string\n");
    return 0;
}

int file_append(void)
{
    printf("File appended\n");
    return 0;
}

int file_delete(const char *p_filename)
{
    if (remove(p_filename) == 0)
    {
        printf("File %s deleted.\n", p_filename);
        return 0;
    }
    else
    {
        fprintf(stderr, "Unable to delete %s\n", p_filename);
        return 1;
    }
}

int file_info(const char *p_filename)
{
    int func_retval = 0;
    struct stat buffer = {0};

    if (lstat(p_filename, &buffer) == -1)
    {
        func_retval = 1;
        goto exit_func;
    }

    if (S_ISBLK(buffer.st_mode))
    {
        printf("Block device\n");
    }
    else if (S_ISCHR(buffer.st_mode))
    {
        printf("Character device\n");
    }
    else if (S_ISDIR(buffer.st_mode))
    {
        printf("Directory\n");
    }
    else if (S_ISFIFO(buffer.st_mode))
    {
        printf("FIFO/pipe\n");
    }
    else if (S_ISLNK(buffer.st_mode))
    {
        printf("Symlink\n");
    }
    else if (S_ISREG(buffer.st_mode))
    {
        printf("Regular file\n");
    }
    else
    {
        printf("Unknown\n");
    }

    printf("Size: %ld bytes\n", buffer.st_size);

    gid_t gid = buffer.st_gid;
    uid_t uid = buffer.st_uid;
    struct group *grp = getgrgid(gid);
    struct passwd *usr = getpwuid(uid);

    if (usr->pw_name)
    {
        printf("User: %s\n", usr->pw_name);
    }
    else
    {
        printf("User: (unknown)\n");
    }

    if (grp->gr_name)
    {
        printf("Group: %s\n", grp->gr_name);
    }
    else
    {
        printf("Group: (unknown)\n");
    }

exit_func:
    return func_retval;
}