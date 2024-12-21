// 孤儿进程：一个父进程退出，而它的一个或多个子进程还在运行，
// 那么那些子进程将成为孤儿进程。孤儿进程将被init进程(进程号为1)所收养，
// 并由init进程对它们完成状态收集工作。
//
// 僵尸进程：一个进程使用fork创建子进程，如果子进程退出，
// 而父进程并没有调用wait或waitpid获取子进程的状态信息，
// 那么子进程的进程描述符仍然保存在系统中。这种进程称之为僵死进程。

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <signal.h>

static void sig_hup(int signo)
{
    printf("SIGHUP received, pid = %ld\n", (long)getpid());
}

static void pr_ids(char *name)
{
    printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tgrp = %ld\n"
           , name, (long)getpid, (long)getppid(), (long)getpgrp(), (long)tcgetpgrp(STDIN_FILENO));
    fflush(stdout);
}

int main()
{
    char c;
    pid_t pid;

    pr_ids("parent");
    if ((pid = fork()) < 0)
    {
        printf("fork error\n");
    }
    else if (pid > 0)
    {
        // 你咋没被收养呢？
        sleep(5);  // sleep to let child stop itself
    }
    else
    {
        pr_ids("child");
        signal(SIGHUP, sig_hup);
        kill(getpid(), SIGTSTP);
        pr_ids("child");
        if (read(STDIN_FILENO, &c, 1) != 1)
        {
            printf("read error %d on controlling TTY\n", errno);
        }
    }
    return(0);
}
