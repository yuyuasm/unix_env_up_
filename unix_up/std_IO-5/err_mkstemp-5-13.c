// tmpnam 创建文件时，另一进程可以用同名创建文件
// mkstemp 没有这个问题
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>


int main()
{	
    char good_tmp[] = "/tmp/dir123456";
//     char *bat_tmp[] = "/tmp/dir777777";

    printf("trying to create first tmp file...\n");
    make_temp(good_tmp);
    printf("trying to create second tmp file...\n");
  //   make_temp(bat_tmp);

    return 0;
}

void make_temp(char *tmp_file)
{
    int fd;
    struct stat sbuf;

    if ((fd = mkstemp(tmp_file)) < 0)
    {
        printf("can't create tmp file\n");
    }
    printf("tmp name = %s\n", tmp_file);
    close(fd);
    if (stat(tmp_file, &sbuf) < 0)
    {
        if (errno == ENOENT)
        {
            printf("file doesn't exist\n");
        }
        else 
        {
            printf("stat failed\n");
        }
    }
    else
    {
        printf("file exists\n");
        unlink(tmp_file);
    }
}
