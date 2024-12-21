// pause 使调用进程在接到一信号前挂起
# include <stdio.h>
# include <signal.h>
# include <unistd.h>

static void sig_usr(int);

int main()
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
        printf("can't catch SIGUSR1\n");
        return(-1);
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
    {
        printf("can't catch SIGUSR2\n");
        return(-1);
    }
    for (;;)
    {
        pause();
    }
}

static void sig_usr(int signo)  // argument is signal number
{
    if (signo == SIGUSR1)
    {
        printf("recevied SIGUSR1\n");
    }
    else if (signo == SIGUSR2)
    {
        printf("recevied SIGUSR2\n");
    }
    else
    {
        printf("recevied signal %d\n", signo);
    }
}
