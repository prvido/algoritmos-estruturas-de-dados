#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, v;

    while (scanf("%d",&n) != EOF && scanf("%d", &v) != EOF)
    {
        bool dentro = false;

        while (v > 0)
        {
            int posicao = 0;
            int aux = v;
            while (aux > 0)
            {
                for (int i = 0; i < aux; i++)
                {
                    posicao += aux;
                    if (posicao == n) dentro = true;
                }
                aux--;
            }
            v--;
        }

        if (dentro) printf("possivel\n");
        else printf("impossivel\n");
    }
    return 0;
}