#include <stdio.h>
#include <stdlib.h>

void iniciaVetor(int *v, int n)
{
    v = (int *) malloc(sizeof(int) * n);
}

void lerVetor(int v[500000], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

void intercala(int v1[500000], int v2[500000], int *v3, int q1, int q2)
{
    int i = 0, j = 0, k = 0;
    while (i < q1 && j < q2)
    {
        if (v1[i] <= v2[j])
        {
            v3[k] = v1[i];
            i++;
        }
        else
        {
            v3[k] = v2[j];
            j++;
        }
        k++;
    }
    while(i < q1)
    {
        v3[k] = v1[i];
        i++;
        k++;
    }
    while(j < q2)
    {
        v3[k] = v2[j];
        j++;
        k++;
    }
}

void imprimeVetor(int v[500000], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", v[i]);
    }
}

int main()
{
    int q1, q2;
    scanf("%d %d", &q1, &q2);

    int v1[500000], v2[500000], v3[1000000];

    lerVetor(v1, q1);
    lerVetor(v2, q2);

    intercala(v1, v2, v3, q1, q2);

    imprimeVetor(v3, q1 + q2);

    return 0;
}