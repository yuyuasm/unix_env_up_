# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>


# define BUFFSIZE 1

int main(int argc, char *argv[])
{
    int val;

    if (argc != 2)
    {
        printf("usage: a.out file\n");
    }

    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
    {
        printf("fcntl error for fd %d\n", atoi(argv[1]));
    }

    switch (val & O_ACCMODE) {
        case O_RDONLY:
            printf("read only\n");
            break;
        case O_WRONLY:
            printf("write only\n");
            break;
        case O_RDWR:
            printf("read write\n");
            break;
        default:
            printf("unknown access mode\n");
            return 0;
    }

    if (val & O_APPEND)
    {
        printf(", append");
    }
    if (val & O_NONBLOCK)
    {
        printf(", nonblocking\n");
    }
    if (val & O_SYNC)
    {
        printf(", synchronous writes\n");
    }

    # if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
        if (val & O_FSYNC)
        {
            printf(", synchronous writes \n");
        }
    # endif

    putchar("\n");

    return 0;
}

