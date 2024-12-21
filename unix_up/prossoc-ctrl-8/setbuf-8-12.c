// 输出不带缓冲，于是每个字符输出调用一次write
// 内核多次在两个进程间切换
# include <stdio.h>
# include <unistd.h>

static void charatatime(char *);

int main()
{

    pid_t pid;

    if ((pid = fork()) < 0)
    {
        printf("fork error\n");
    }
    else if (pid == 0)
    {
        charatatime("output from child\n");
    }
    else
    {
        charatatime("output from parent\n");
    }
    return(0);
}

static void charatatime(char *str)
{
    char *ptr;
    int c;
    // void setbuf(FILE *stream, cahr *buffer // 用户缓冲)
    setbuf(stdout, NULL);
    for (ptr = str; (c = *ptr++) != 0;)
    {
        putc(c, stdout);
    }
}
