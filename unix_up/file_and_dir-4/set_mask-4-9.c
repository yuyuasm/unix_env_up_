# include <stdio.h>
# include <sys/stat.h>


int main()
{
    struct stat statbuf;

    if (stat("foo", &statbuf) < 0)
    {
        printf("stat error for foo\n");
        return 0;
    }
    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
    {
        printf("chmod error for foo\n");
        return 0;
    }

    if ((chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    {
        printf("chmod error for bar\n");
        return 0;
    }

    return 0;
}
