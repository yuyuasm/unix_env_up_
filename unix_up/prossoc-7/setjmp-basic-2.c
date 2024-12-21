// basic try-catch
# include <stdio.h>
# include <setjmp.h>

# define try do { jmp_buf ex_buf__; if (!setjmp(ex_buf__)) {
# define catch } else {
# define etry } } while (0)
# define throw longjmp(ex_buf__, 1)

/*
 * 宏孩儿注释版 

int main()
{
    // Linux和其它代码库里的宏都用do/while(0)来包围执行逻辑，
    // 因为它能确保宏的行为总是相同的，
    // 而不管在调用代码中使用了多少分号和大括号。
    // https://www.cnblogs.com/lanxuezaipiao/p/3535626.html
    do
    {
        jmp_buf tmp;
        if (!setjmp(tmp))
        {

            {
                printf("In try statement\n");
                longjmp(tmp, 1);
                printf("I do not appear\n");
            }
        } 
        else 
        {
            {
                printf("Got exception!\n");
            }
        }
    } while (0)

    return(0);
}
*/

int main()
{
    try
    {
        printf("In try statement\n");
        throw;
        printf("I do not appear\n");
    }
    catch
    {
        printf("Got exception!\n");
    }
    etry;

    return 0;
}
