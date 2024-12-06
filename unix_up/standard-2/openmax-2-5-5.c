# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <unistd.h>

# ifdef OPEN_MAX
static long openmax = OPEN_MAX;
# else
static long openmax = 0;
# endif


# define OPEN_MAX_GUESS 256

long open_max()
{
    if (openmax == 0)
    {
        errno = 0;
    }
    if ((openmax = sysconf(_SC_OPEN_MAX)) < 0)
    {
        if (errno == 0)
        {
            openmax = OPEN_MAX_GUESS;
        }
        else
        {
            printf("sysconf error for _SC_OPEN_MAX\n");
            return 0;
        }
    }
    return(openmax);
}
