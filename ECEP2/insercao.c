#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *v, int n)
{
    for (int i = 0; i <  n; i++)
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

void insercao(int *v, int n)
{
    int c = v[n - 1];
    int achei = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (achei == 0)
        {

            if (c < v[i-1])
            {
                v[i] = v[i - 1];
                imprimeVetor(v, n);
            }
            else
            {
                achei = 1;
                v[i] = c;
            }
        }
    }

    imprimeVetor(v, n);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *v = (int*) malloc(sizeof(int) * n);

    lerVetor(v, n);
    insercao(v, n);

    return 0;
}