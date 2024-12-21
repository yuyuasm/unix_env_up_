// 用 getc 和 putc 将标准输入复制到标准输出
# include <stdio.h>

int main()
{	
    int c;
    while ((c = getc(stdin)) != EOF)
    {
        if (putc(c, stdout) == EOF)
        {
            printf("output error\n");
	    return(-1);
        }
    }
    if (ferror(stdin))
    {
        printf("input error\n");
	return(-1);
    }

    return(0);
}
