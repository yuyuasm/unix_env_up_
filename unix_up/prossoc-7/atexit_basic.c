# include <stdio.h>
# include <stdlib.h>

static void exit_func1();
static void exit_func2();

int main()
{
    atexit(exit_func2);
    atexit(exit_func1);
    atexit(exit_func2);
    printf("Test exit and atextit\n");
    exit(0);
}

static void exit_func1()
{
    printf("exit_func1() is called\n");
}

static void exit_func2()
{
    printf("exit_func2() is called\n");
}
