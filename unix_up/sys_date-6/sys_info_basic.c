// 或取当前主机和操作系统信息
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/utsname.h>
# include <errno.h>

int main()
{
    struct utsname name;
    if (uname(&name) == -1)
    {
        perror("uname() error");
        exit(-1);
    }
    printf("system name is: %s\n", name.sysname);
    printf("node name is: %s\n", name.nodename);
    printf("release name is: %s\n", name.release);
    printf("version name is: %s\n", name.version);
    printf("machine name is: %s\n", name.machine);

    return(0);
}
