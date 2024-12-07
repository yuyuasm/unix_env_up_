# include <stdio.h>
# include <unistd.h>

int globvar = 6;
char buf[] = "a write to stdout\n";

int main()
{
    int var;
    pid_t pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
    {
        printf("write error\n");
        return(-1);
    }
    printf("before fork\n");  // we don't flush stdout
    if ((pid = fork()) < 0)
    {
        printf("fork error\n");
        return(-1);
    }
    else if (pid == 0)
    {
        globvar++;
        var++;
    }
    else
    {
        sleep(2);
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

    return(0);

}
