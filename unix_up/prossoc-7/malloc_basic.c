# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main()
{
    int n;
    int *p_data;
    printf("Enter the number: ");
    scanf("%d", &n);

    p_data = (int*)malloc(sizeof(int)*n);
    memset(p_data, 0, sizeof(int)*n);
    printf("p_data address is :%p\n", p_data);
    free(p_data);

    p_data = (int*)calloc(n, sizeof(int));
    printf("p_data address is :%p\n", p_data);
    p_data = realloc(p_data, sizeof(int) * (n + 10));
    printf("p_data address is: %p\n", p_data);
    free(p_data);

    exit(0);
}
