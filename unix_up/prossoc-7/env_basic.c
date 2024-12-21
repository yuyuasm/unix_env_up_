#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *name;
    char *value;
    char *str = "LENGTH=10";
    char *pvalue;
    name = "QUERY";
    value = "Hello,world";
    //设置环境变量，1表示若那么存在，则先先删除
    setenv(name,value,1);

    putenv(str);

    pvalue = getenv(name);
    printf("%s = %s\n", name, value);

    pvalue = getenv("LENGTH");
    printf("LENGTH = %s\n", pvalue);
    unsetenv("LENGTH");

    pvalue = getenv("HOME");
    printf("HOME = %s\n", pvalue);

    exit(0);
}
