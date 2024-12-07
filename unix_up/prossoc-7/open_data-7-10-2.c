// 设置流缓冲


# include <stdio.h>

# define BUFSIZE 4096

FILE open_date(void)
{
    FILE *fp;
    char databuf[BUFSIZE];

    if ((fp = fopen("datafile", "r")) == NULL)
    {
        return(NULL);
    }
    if (setvbuf(fp, databuf, _IOLBF, BUFSIZE) != 0)
    {
        return(NULL);
    }
    return(fp);
}
