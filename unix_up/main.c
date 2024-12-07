# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int main()
{
    pid_t pid;

    if ((pid = fork()) < 0)
    {
        perror("fork error\n");
    }
    else if ((pid == 0))  // 判定子进程
    {
        printf("child getpid() = %d\n", getpid());
    }
    else if ((pid > 0))  // 判断父进程
    {
        printf("parent getpid() = %d\n", getpid());
    }

    return(0);
}
