# include <stdio.h>
# include <stdlib.h>


/*
                nitems 要分配元素个数
                size 元素的大小
void *calloc(size_t nitems, size_t size)
calloc 会设置初始化为 0
*/


int main()
{
    int i, n;
    int *a;

    printf("输入元素个数\n");
    scanf("%d", &n);

    a = (int*)calloc(n, sizeof(int));
    printf("输入 %d 个数字\n", n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    printf("输入数字为: ");
    for (i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    free(a);

    return(0);
}
