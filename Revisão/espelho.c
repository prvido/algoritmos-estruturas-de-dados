#include <stdio.h>

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    int j = 10;
    int k = 1000;
    int cont = 0;

    for (int i = 0; i < 4; i++)
    {
        if ((a % j) / (j/10) != (b /k) % 10) cont++;

        j *= 10;
        k /= 10;
    }

    if (cont != 0) printf("nao espelho\n");
    else printf("espelho\n");

    return 0;
}