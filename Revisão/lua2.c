#include <stdio.h>

int main()
{
    int n, m1, m2;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &m1, &m2);

        if (m2 <= 2) printf("Nova\n");

        else if (m2 >= 97) printf("Cheia\n");

        else
        {
           if (m1 < m2) printf("Crescente\n");
           else printf("Minguante\n");
        }
    }

    return 0;
}