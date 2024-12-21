// pr_exit 宏打印终止状态
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>

void pr_exit(int status)
{
    if (WIFEXITED(status))
    {
        printf("正常退出，退出状态为: %d\n", WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status))
    {
        printf("不正常退出，退出状态为: %d\n", WTERMSIG(status));
    }
    else if (WIFSTOPPED(status))
    {
        printf("子进程停止，信号代码为：%d\n", WSTOPSIG(status));
    }
}

int main()
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0)
    {
        printf("fork error\n");
        return(-1);
    }
    else if (pid == 0)
    {
        return(7);
    }

    if (wait(&status) != pid)
    {
        printf("wait error\n");
    }
    pr_exit(status);

    if ((pid = fork()) < 0)
    {
        printf("fork error\n");
        return(-1);
    }
    else if (pid == 0)
    {
        abort();
    }

    if (wait(&status) != pid)
    {
        printf("wait error\n");
        return(-1);
    }
    pr_exit(status);

    if ((pid = fork()) < 0)
    {
        printf("fork error\n");
        return(-1);
    }
    else if (pid == 0)
    {
        status = 0;
    }

    if (wait(&status) != pid)
    {
        printf("wait error\n");
        return(-1);
    }
    pr_exit(status);
    return(0);
}
