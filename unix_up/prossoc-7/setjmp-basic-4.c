// basic try-catch
# include <stdio.h>
# include <setjmp.h>

# define try do {jmp_buf ex_buf__; switch (setjmp(ex_buf__)) { case 0: while(1) {
# define catch(x) break; case x:
# define finally break; } default: {
# define etry break; } } } while (0)
# define throw(x) longjmp(ex_buf__, x)

# define foo_exception (1)
# define bar_exception (2)
# define baz_exception (3)


int main()
{
    try
    {
        printf("In try statement\n");
        throw(bar_exception);
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
    finally
    {
        printf("...et in arcadia Ego\n");
    }
    etry;

    return(0);
}
