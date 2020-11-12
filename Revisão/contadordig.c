#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int cont = 1;
        while(n / 10 > 0)
        {
            n /= 10;
            cont++;
        }
        printf("%d\n", cont);
    }

    return 0;
}