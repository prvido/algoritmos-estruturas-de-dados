#include <stdio.h>

int main()
{
    int anoAtual, anoNascimento;
    char nome[20];

    scanf("%d %s %d", &anoAtual, nome, &anoNascimento);

    printf("%s, voce completa %d anos de idade neste ano.\n", nome, anoAtual - anoNascimento);

    return 0;
}