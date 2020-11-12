#include <stdlib.h>
#include <stdio.h>

void lerVetor(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

void imprimeVetor(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1) printf("%d ", v[i]);
        else printf("%d\n", v[i]);
    }
}

int checkOrdenadoC(int *v, int n)
{
    int i = 0;
    while (v[i] <= v[i + 1] && i < n - 1) i++;

    if (i == n - 1) return 1;
    else return 0;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int *v = (int *) malloc(sizeof(int) * n);

        lerVetor(v, n);


        if (checkOrdenadoC(v, n) || n == 0)
            printf("S\n");
        else
            printf("N\n");

        free(v);
    }

    return 0;
}