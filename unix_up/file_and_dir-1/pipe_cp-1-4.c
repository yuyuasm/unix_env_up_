# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFSIZE 4096


int main(int argc, char *argv[])
{
    int n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            printf("write error\n");
            exit(0);
        }
    }

    if (n < 0)
    {
        printf("read error\n");
        exit(0);
    }

    exit(0);
}
