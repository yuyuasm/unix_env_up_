// signal 返回处理程序之前的值，当发生错误返回 sig_err
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>


static void sighandler(int);

int main()
{
    signal(SIGINT, sighandler);

    while (1)
    {
        printf("开始休眠一秒\n");
        sleep(1);
    }

    return(0);
}

static void sighandler(int signum)
{
    printf("捕获信号 %d, 跳出\n", signum);
    exit(1);
}
