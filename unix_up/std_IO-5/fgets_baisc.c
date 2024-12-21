 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <wchar.h>
 
 #define BUFSIZE 1024
 
 int main()
 {
     char *filename = ".//test.log";
     char buf[BUFSIZE];
     char line[100];
     FILE *fp;
     memset(line,0,100);
     //打开文件，不存在则创建
     fp = fopen(filename,"w+");
     if(fp == NULL)
     {
         perror("fopen() error");
         exit(-1);
     }
     //设置为字节宽度
     if(fwide(fp,-1) < 0)
         printf("byte stream\n");
     //设置为行缓冲
     setvbuf(fp,buf,_IOLBF,BUFSIZE);
     printf("Enter file content:\n");
     gets(line);
     printf("write to file.\n");
     fputs(line,fp);
     close(fp);
      fp = fopen(filename,"r+");
     if(fp == NULL)
     {
         perror("fopen() error");
         exit(-1);
     }
     printf("read from file.\n");
     fgets(line,99,fp);
     printf("%s\n",line);
     close(fp);
     return 0;
 }
