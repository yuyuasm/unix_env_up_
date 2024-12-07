# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


int main(int argc, char *argv[])
{
    printf("helle world from process ID: %ld\n", (long) getpid());

    exit(0);
}
