#include <stdio.h>
#include <stdlib.h>

struct FilaCircular
{
    int *itens;
    int inicio, fim, tamanho, quantidade;
};

void iniciaFilaCircular(struct FilaCircular *fila, int n)
{
    if (fila->tamanho != n)
    {
        fila->tamanho = n;
        fila->itens = (int*) malloc(sizeof(int) * n - 1);
    }
    fila->inicio = -1;
    fila->fim = -1;
    fila->quantidade = 0;
}

void printarFila(struct FilaCircular fila)
{
    for (int i = 0; i < fila.tamanho; i++)
    {
        printf("%d ", fila.itens[i]);
    }
    printf("\n");
}

void inserir(struct FilaCircular *fila, int x)
{
    if (fila->quantidade == fila->tamanho - 1) return;

    fila->fim = (fila->fim + 1) % fila->tamanho;

    if (fila->quantidade == 0)
    {
        fila->inicio = (fila->inicio + 1) % fila->tamanho;
        fila->itens[fila->inicio] = x;
    }

    else
    {
        fila->itens[fila->fim] = x;
    }

    fila->quantidade++;
}

int remover(struct FilaCircular *fila)
{
    if (fila->inicio != -1)
    {
        int aux = fila->itens[fila->inicio];

        fila->inicio = (fila->inicio + 1) % fila->tamanho;

        fila->quantidade--;

        if (fila->quantidade == 0) iniciaFilaCircular(fila, fila->tamanho);

        return aux;
    }
    return -1;
}

int main()
{
    int n, x;
    char op;
    scanf("%d", &n);

    struct FilaCircular fila;
    iniciaFilaCircular(&fila, n);

    while(scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &x);
            // Inserir
            inserir(&fila, x);
        }
        else if (op == 'D')
        {
            // Imprimir valor excluido
            int retorno = remover(&fila);
            if (retorno != -1) printf("%d\n", retorno);
        }
    }

    return 0;
}