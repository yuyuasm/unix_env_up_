#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <pwd.h>
#include <string.h>

static void my_alarm(int signo)
{
    struct passwd *rootptr;
    printf("in signal handler.\n");
    if ((rootptr = getpwnam("root")) == NULL)
    {
        perror("getpwnam() error");
        exit(-1);
    }
    printf("return value:,pw_name = %s\n",rootptr->pw_name);
    alarm(1);
}

int main()
{

    struct passwd  *ptr;
    signal(SIGALRM,my_alarm);
    alarm(1);
    while(1)
    {
        if((ptr = getpwnam("yuyu")) == NULL)
        {
             perror("getpwnam() error");
            exit(-1);
        }
        if(strcmp(ptr->pw_name,"yuyu") != 0)
            printf("return value corrupted!,pw_name = %s\n",ptr->pw_name);
        else
            printf("return value not corrupted!,pw_name = %s\n",ptr->pw_name);

    }
}
