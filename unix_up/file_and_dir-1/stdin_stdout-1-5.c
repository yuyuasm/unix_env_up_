# include <stdio.h>
# include <stdlib.h>

int main()
{
    int c;

    while ((c = getc(stdin)) != EOF)
    {
        if (putc(c, stdout) == EOF)
        {
            printf("output error\n");
            exit(0);
        }
    }

    if (ferror(stdin))
    {
        printf("input error\n");
        exit(0);
    }

    exit(0);
}
