# include <stdio.h>
# include <setjmp.h>

jmp_buf jmpbuffer;

int fun_a(int v)
{
    int r = v * 2 - 1;
    if (r < 0)
    {
        longjmp(jmpbuffer, 1);
    }
    return(r);
}

int fun_b(int v)
{
    int r = fun_a(v) + 6;
    if (r > 10)
    {
        longjmp(jmpbuffer, 2);
    }
    return(r);
}

int fun_c(int v)
{
    int r = fun_b(v) * 5 - 21;
    return(r);
}

int main()
{
    // 设置跳转目标
    int jmpval = setjmp(jmpbuffer);
    if (jmpval == 1)
    {
        printf("fun_a error\n");
    }
    else if (jmpval == 2)
    {
        printf("fun_b error\n");
    }
    else
    {

        int x = 1;
        int result = fun_c(x);
        printf("result = %d\n", result);
    }
    return(0);
}

