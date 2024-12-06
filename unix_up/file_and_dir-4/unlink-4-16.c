// 打开一个文件，并解除它的链接
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int main()
{
    if (open("tmpfile", O_RDWR) < 0)
    {
        printf("open error\n");
        return 0;
    }
    if (unlink("tmpfile") < 0)
    {
        printf("unlink error\n");
    }
    printf("file unlinked\n");
    sleep(15);
    printf("done\n");

    return 0;
}
