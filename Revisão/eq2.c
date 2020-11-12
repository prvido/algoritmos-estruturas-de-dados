#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    float d = b*b - 4*a*c;
    float r = sqrt(d);
    float x1 = (-1*b - r) / (2 * a);
    float x2 = (-1*b + r) / (2 * a);
    printf("%.4f %.4f\n", x2, x1);
    return 0;
}