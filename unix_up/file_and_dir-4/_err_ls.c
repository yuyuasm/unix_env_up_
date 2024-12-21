# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>


static void show_all_file(char* file_path);

int main(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++)
    {
        show_all_file(argv[i]);
    }
    return(0);
}

static void show_all_file(char* file_path)
{
    struct stat st;
    DIR *dp;
    struct dirent* dirp;
    char *pstr;

    if (lstat(file_path, &st) == -1)
    {
        perror("lstat() error");
        exit(-1);
    }

    // 判断是否是目录文件
    if (S_ISDIR(st.st_mode) == 0)
    {
        printf("File: %s\n", file_path);
    }
    else
    {
        printf("Directory: %s\n", file_path);
        pstr = file_path + strlen(file_path);
        *pstr++ = '/';
        *pstr = 0;
        // 打开目录
        if ((dp = opendir(file_path)) == NULL)
        {
            printf("opendir() error\n");
            exit(-1);
        }
        // 读取目录下内容
        while ((dirp = readdir(dp)) != NULL)
        {
            if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            {
                continue;
            }
            strcpy(pstr, dirp->d_name);
            show_all_file(file_path);
        }
    }
}


