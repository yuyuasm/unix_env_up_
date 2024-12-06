# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

# define MAXLINE 4096

int main()
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0;  // replace newlinw with null;
        }

        if ((pid = fork()) < 0)
        {
            printf("fork error\n");
            exit(0);
        }
        else if (pid == 0)
        {
            execlp(buf, buf, (char *) 0);
            printf("couldn't execute: %s\n", buf);
            exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            printf("waitpid error\n");
            exit(0);
        }

        printf("%% ");
    }

    exit(0);
}
