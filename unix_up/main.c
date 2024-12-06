// 用已知模式填充缓冲区
# include <stdio.h>
# include <string.h>

# define BSZ 48

int main()
{	
    FILE *fp;
    char buf[BSZ];

    memset(buf, 'a', BSZ - 2);  // 用 a 改写缓冲区
    buf[BSZ - 2] = '\0';
    buf[BSZ - 1] = 'X';
    // fmemopen 在缓冲区开始处放置 null 字节
    if ((fp = fmemopen(buf, BSZ, "w+")) == NULL)
    {
        printf("fmemopen error\n");
    }
    printf("initial buffer contents: %s\n", buf);
    fprintf(fp, "Hello, World!");
    printf("before flush: %s\n", buf);
    // 流冲洗缓冲区才会变化, null 追加结尾
    fflush(fp);
    printf("after fflush: %s\n", buf);
    printf("len of string in buf = %ld\n", (long) strlen(buf));

    // 用 b 填充缓冲区
    memset(buf, 'b', BSZ - 2);
    buf[BSZ - 2] = '\0';
    buf[BSZ - 1] = 'X';
    fprintf(fp, "Hello, World!");
    // fseek 引起缓冲区清洗, 再次追加 null
    fseek(fp, 0, SEEK_SET);
    printf("after fseek: %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    // 用 c 填充缓冲区
    memset(buf, 'c', BSZ - 2);
    buf[BSZ - 2] = '\0';
    buf[BSZ - 1] = 'X';
    fprintf(fp, "Hello, World!");
    // 没有追加 null
    fclose(fp);
    printf("after flclose: %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    return 0;

}
