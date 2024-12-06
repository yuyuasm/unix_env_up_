// tmpfile 创建临时文件，在关闭后自动删除
# include <stdio.h>


# define MAXLINE 80

int main()
{	
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;

    printf("%s\n", tmpnam(NULL));  // first tmp name

    tmpnam(name);  // second tmp name
    printf("%s\n", name);

    if ((fp = tmpfile()) == NULL)  // create tmp file
    {
        printf("tmpfile error\n");
        return 0;
    }
    fputs("one line of output\n", fp);  // write to tmp file
    rewind(fp);  // then read it back
    if (fgets(line, sizeof(line), fp) == NULL)
    {
        printf("fgets error\n");
        return 0;
    }
    fputs(line, stdout);  // print the line we write

    return 0;
}
