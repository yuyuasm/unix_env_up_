// 用 getc 和 putc 将标准输入复制到标准输出
# include <stdio.h>

# define MAXLINE 80

int main()
{	
    char buf[MAXLINE];

    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (fputs(buf, stdout) == EOF)
        {
            printf("output error\n");
            return 0;
        }
    }
    if (ferror(stdin))
    {
        printf("input error\n");
        return 0;
    }

    return 0;
}
