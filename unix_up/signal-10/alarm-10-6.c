// alarm 每秒产生一次 sigalrm 信号
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <pwd.h>


static void my_alarm(int signo)
{
    struct passwd *rootptr;

    printf("in signal handler\n");
    if ((rootptr = getpwnam("root")) == NULL)
    {
        printf("getpwnam(root) error\n");
    }
    alarm(1);
}

int main()
{
    struct passwd *ptr;

    signal(SIGALRM, my_alarm);
    alarm(1);
    for (;;)
    {
        if ((ptr = getpwnam("yuyu")) == NULL)
        {
            printf("getpwnam error\n");
        }
        if (strcmp(ptr->pw_name, "yuyu") != 0)
        {
            printf("return value corrupted, pw_name = %s\n", ptr->pw_name);
        }
    }

    return(0);
}
