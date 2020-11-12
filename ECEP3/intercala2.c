#include <stdio.h>
#include <stdlib.h>

void lerVetor (int v[1000000], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
}

void intercala(int *v, int n)
{
    int aux[999999];
    for (int i = 0; i <= 999999; i++)
        aux [i] = 0;

    for (int i = 0; i < n; i++)
    {
        aux[v[i]]++;
    }

    int j = 0, i = 0;
    while(i <= 999999)
        if (aux[i] > 0)
        {
            v[j] = i;
            aux[i]--;
            j++;
        }
        else
        {
            i++;
        }
}

void imprimeVetor(int v[1000000], int n)
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

    int v[1000000];
    lerVetor(v, q1 + q2);

    intercala(v, q1 + q2);

    imprimeVetor(v, q1 + q2);

    return 0;
}