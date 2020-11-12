#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int time1, time2, cont1, cont2, golsFora1, golsFora2, gols1, gols2;
    char x;

    for (int i = 0; i <n; i++)
    {
        cont1 = 0;
        cont2 = 0;
        gols1 = 0;
        gols2 = 0;
        golsFora1 = 0;
        golsFora2 = 0;

        for (int j = 0; j < 2; j++)
        {
            scanf("%d x %d", &time1,  &time2);

            if (j == 0)
            {
                if (time1 > time2) cont1++;
                else if (time2 > time1) cont2++;
                gols1 += time1;
                gols2 += time2;
                golsFora2 = time2;
            }
            else
            {
                if (time1 > time2) cont2++;
                else if (time2 > time1) cont1++;
                gols1 += time2;
                gols2 += time1;
                golsFora1 = time2;
            }
        }

        if (cont1 > cont2) printf("Time 1\n");
        else if (cont2 > cont1) printf("Time 2\n");
        else
        {
            if (gols1 > gols2) printf("Time 1\n");
            else if (gols2 > gols1) printf("Time 2\n");
            else
            {
                if (golsFora1 > golsFora2) printf("Time 1\n");
                else if (golsFora2 > golsFora1) printf("Time 2\n");
                else printf("Penaltis\n");
            }
        }
    }
    return 0;
}