#include <stdio.h>

int main()
{
    int s;

    int cont = 0;
    int divs = 1000;

    scanf("%d",&s);


    if (s > 1000 && s < 9999)
    {
        while(s > 0)
        {
            if (s / divs != 0)
            {
                cont++;
            }
            s %= divs;
            divs /= 10;
        }
    }

    if (cont == 4) printf("SIM\n");
    else printf("NAO\n");
    return 0;
}