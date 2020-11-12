#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float x1, x2;

    scanf("%f %f %f", &a, &b, &c);

    float delta = (b*b) - (4*a*c);

    if (delta > 0)
    {
        x1 = ((-1 * b) + sqrt(delta)) / (2 * a);
        x2 = ((-1 * b) - sqrt(delta)) / (2 * a);
        printf("%.4f %.4f\n", x1, x2);
    }
    else if (delta == 0)
    {
        x1 = ((-1 * b) / (2 * a);
        printf("%.4f\n", x1);
    }
    else printf("nao ha raiz real\n");

    return 0;
}