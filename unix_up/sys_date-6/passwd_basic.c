#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <shadow.h>


int main()
{
    struct spwd *pspwd;
    struct passwd *ptr;
    pspwd = getspnam("yuyu");
    if (pspwd == NULL)
    {
        perror("getspnam() error");
        exit(-1);
    }
    printf("yuyu user infomation as follow:\n");
    printf("user_name is: %s\n", pspwd->sp_namp);
    printf("user_passwd is: %s\n", pspwd->sp_pwdp);
    printf("*************************\n");

    setspent();
    while ((pspwd = getspent()) != NULL)
    {
        printf("user_name is: %s\n", pspwd->sp_namp);
        printf("user_passwd is: %s\n", pspwd->sp_pwdp);
    }
    endspent();

    return(0);
}

