# include <stdio.h>
# include <unistd.h>

int main()
{
    if (chdir("/tmp") < 0)
    {
        printf("chdir failed\n");
    }
    printf("chdir to /tmp succeded\n");

    return 0;
}
