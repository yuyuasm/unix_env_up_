# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <dirent.h>

int main(int argc, char *argv[])
{
    int i, fd;
    struct stat statbuf;
    struct timespec times[2];
    for (i = 1; i < argc; i++)
    {
        if (stat(argv[i], &statbuf) < 0)  // fetch current time
        {
            printf("%s: stat error\n", argv[i]);
            continue;
        }
        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0)  // truncate
        {
            printf("%s: stat error\n", argv[i]);
            continue;
        }
        times[0] = statbuf.st_atime;
        times[1] = statbuf.st_mtime;
        if (futimes(fd, times) < 0)  // reset times
        {
            printf("%s: funtimes error\n", argv[i]);
        }
        close(fd);
    }

    return 0;
}
