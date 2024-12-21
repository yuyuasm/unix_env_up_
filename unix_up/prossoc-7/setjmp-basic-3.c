// basic try-catch
# include <stdio.h>
# include <setjmp.h>

# define try do { jmp_buf tmp; switch (setjmp(tmp)) { case 0:
# define catch(x) break; case x:
# define etry } } while (0)
# define throw(x) longjmp(tmp, x)

# define foo_exception (1)
# define bar_exception (2)
# define baz_exception (3)

/*
 * 注释
int main()
{
    do 
    {
        jmp_buf tmp;
        switch (setjmp(tmp))
        {
            case 0:        
            {
                printf("In try statement\n");
                longjmp(tmp, baz_exception);
                printf("I do not appear\n");
            }
            break;
            case foo_exception:
            {
                printf("Got foo!\n");
            }
            break;
            case bar_exception:
            {
                printf("Got bar!\n");
            }
            break;
            case baz_exception:
            {
                printf("Got baz\n");
            }
        }
    } while (0);


    return 0;
}
*/

int main()
{
    try
    {
        printf("In try statement\n");
        throw(baz_exception);
        printf("I do not appear\n");
    }
    catch (foo_exception)
    {
        printf("Got foo!\n");
    }
    catch (bar_exception)
    {
        printf("Got bar!\n");
    }
    catch (baz_exception)
    {
        printf("Got baz!\n");
    }
    etry;

    return 0;
}
