#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int cont = 0;

        while((n / 10 > 0))
        {

            if ((n % 10) % 2 == 0) cont++;

            n /= 10;
        }
        if ((n % 10) % 2 == 0) cont++;
        printf("%d\n", cont);
    }

    return 0;
}