# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void sig_child(int signo)
{
    int status;
    if (waitpid(-1, &status, 0) != -1)
    {
        printf("child process exit.status = %d\n", status);
    }
    else
    {
        perror("waitpid() error");
        exit(-1);
    }
}

int main()
{
    pid_t pid;
    /* SIGCHLD 信号名称 sig_child 调用函数 */
    signal(SIGCHLD, sig_child);
    if ((pid = fork()) == -1)
    {
        perror("fork() error");
    }
    else if (pid == 0)  /* 子进程 */
    {
        printf("I am child process.\n");
        exit(0);
    }
    else
    {
        /* ??? */
        sleep(3);
        printf("I am parent process.\n");
    }
    exit(0);
}
