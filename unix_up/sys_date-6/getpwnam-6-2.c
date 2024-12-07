// getpwnam 获取口令文件项


# include <pwd.h>
# include <stddef.h>
# include <string.h>
# include <stdio.h>


struct passwd * getpwnam(const char *name)
{
    struct passwd *ptr;

    setpwent();  // 指向密码文件开头
    while ((ptr = getpwent()) != NULL)
    {
        if (strcmp(name, ptr->pw_name) == 0)
        {
            break;
        }
    }
    endpwent();
    return(ptr);
}

