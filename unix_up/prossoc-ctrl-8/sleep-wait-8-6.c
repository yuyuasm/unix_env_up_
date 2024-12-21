// 僵死进程
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

int main()
{
    pid_t pid;
    if ((pid = fork()) < 0)
    {
        printf("fork error\n");
        return(-1);
    }
    else if (pid == 0)
    {
        if ((pid = fork()) < 0)  // first child
        {
            printf("fork error\n");
            return(-1);
        }
        else if (pid > 0)
        {
            return(0);
        }
        // 看不懂
        sleep(2);
        printf("second child, parent pid = %ld\n", (long)getppid());
        return(0);
    }
    if (waitpid(pid, NULL, 0) != pid)
    {
        printf("waitpid error\n");
    }

    return(0);
}
