# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>


void sig_handler(int num)
{
    printf("receive the signal %d.\n", num);
    alarm(2);
}

int main()
{
    // sigalrm 闹钟信号
    signal(SIGALRM, sig_handler);
    alarm(2);
    while (1)
    {
        // 可中断暂停
        pause();
    }
    return(0);
}
