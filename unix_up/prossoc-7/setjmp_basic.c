# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <setjmp.h>

static void func1();
static void func2();
static void func3();

jmp_buf tmp_jmp_buf;

int main()
{
    int ret;
    ret = setjmp(tmp_jmp_buf);
    switch (ret)
    {
        case 1:
            printf("func1 is error.\n");
            exit(-1);
        case 2:
            printf("func2 is error.\n");
            exit(-1);
        case 3:
            printf("func3 is error.\n");
            exit(-1);
    }
    func1();
    exit(0);
}

static void func1()
{
    func2();
}

static void func2()
{
    func3();
}

static void func3()
{
    longjmp(tmp_jmp_buf, 3);
}
