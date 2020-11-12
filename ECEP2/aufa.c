#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, x, i;
    scanf("%d %d", &n, &k);
    int v[1000001];

    for (i = 0; i < 1000001; i++)
    {
        v[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        v[x]++;
    }

    i = 1000000;
    int soma = 0, j = 0;

    while (i >= 0 && j < k)
    {
        if (v[i] > 0)
        {
            soma += i;
            j++;
            v[i]--;
        }
        else
            i--;
    }

    int nota = soma / k;

    printf("%d\n", nota);
    return 0;
}