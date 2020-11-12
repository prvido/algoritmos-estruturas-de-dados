#include <stdio.h>
#include <stdlib.h>

struct Lista
{
    int *itens;
    int quantidade;
    int tamanho;
};

void iniciaLista(struct Lista*, int);
void inserir(struct Lista*, int);
void remover(struct Lista *, int);
void deslocaDir(struct Lista*, int);
void deslocaEsq(struct Lista*, int);
int buscaBinaria(int *, int, int, int);
void printarLista(struct Lista);

int main()
{
    int q, x;

    scanf("%d", &q);

    struct Lista lista;
    iniciaLista(&lista, q);

    char op;

    for (int i = 0; i < q; i++)
    {
        scanf("\n%c", &op); // PRECISA TER UM \n ANTES DO %C SENÃO NÃO FUNCIONA

        if (op == 'I')
        {
            // Inserção
            scanf("\n%d", &x);
            inserir(&lista, x);
        }
        else if (op == 'E')
        {
            // Remoção
            scanf("\n%d", &x);
            remover (&lista, x);
        }
    }

    printarLista(lista);

    return 0;
}

void iniciaLista(struct Lista *l, int n)
{
    l->itens = malloc(sizeof(int) * n);
    l->tamanho = n;
    l->quantidade = 0;
}

void inserir(struct Lista *l, int x)
{
    if (l->quantidade == 0)
    {
        l->itens[0] = x;
        l->quantidade ++;
    }
    else if (buscaBinaria (l->itens, 0, l->quantidade - 1, x) == -1)
    {
        int i = 0;

        while (i < l->quantidade && l->itens[i] < x)
        {
            i++; //encontro a posição para inserir o elemento
        }
            deslocaDir(l, i);

            l->itens[i] = x; // colocando o número na posição certa
            l->quantidade ++; // aumentando a quantidade de elementos na lista
    }
}

void remover(struct Lista *l, int x)
{
    int i = 0;

    if (buscaBinaria(l->itens, 0, l->quantidade - 1, x) != -1) // quer dizer que tem o elemento
    {
        while (i < l->quantidade && l->itens[i] != x)
            i++;
        deslocaEsq(l, i);
        l->quantidade--;
    }
}

void deslocaDir (struct Lista *l, int i)
{
    int k;
    for (k = l->quantidade - 1; k >= i; k--)
        l->itens[k+1] = l->itens[k]; // deslocando os elementos para a direita
}
void deslocaEsq (struct Lista *l, int i)
{
    int k;
    for (k = i;k < l->quantidade; k++)
    {
        l->itens[k] = l->itens[k+1];
    }
}

void printarLista (struct Lista l)
{
    for (int i = 0; i < l.quantidade; i++)
    {
        printf("%d\n", l.itens[i]);
    }
}

int buscaBinaria(int *v, int esq, int dir, int x)
{
    int meio;
    if (esq <= dir)
    {
        meio = (esq + dir) / 2;

        if (v[meio] == x) return meio;
        else if (v[meio] > x) return buscaBinaria(v, esq, meio-1, x);
        else return buscaBinaria(v, meio+1, dir, x);
    }
    return -1;
}
int buscaLinearRecursiva (int *v, int tamanho, int x)
{
    if (n == 0 || v[n - 1] == x) return -1;
    else return buscaLinearRecursiva(v, -1, x);
}
int buscaBinaria(int *v, int n, int x)
{
    int esq=0, dir=n-1, meio;
    
    while(esq<=dir)
    {
        meio = (esq+dir)/2;
        
        if(v[meio] == x)
        {
            return meio;
        }
        else if(v[meio] > x)
        {
         dir = meio-1;
        }
        else
        {
            esq = meio + 1;
        }
    }
    return -1;
}