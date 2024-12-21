# include <stdio.h>
# include "try.h"

static void func1();
static void func2();

int main()
{
    printf("Hello, World!\n");
    try
    {
        printf("start: ");
        throw(2);
        printf("dd...\n");
    }
    catch (1)
    {
        printf("func1 error\n");
    }
    catch (2)
    {
        printf("func2 error\n");
    }
    finally
    {
        printf("end\n");
    }
    etry;

    return(0);
}
