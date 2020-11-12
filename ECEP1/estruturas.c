#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Lista
{
    struct Estrutura *itens;
    int tamanho, quantidade;
};

struct Estrutura
{
    int *itens;
	int inicio, fim, tamanho, id, quantidade;
};

void iniciaLista (struct Lista *lt, int n)
{
    lt->itens = (struct Estrutura *) malloc(sizeof(struct Estrutura) * n);
    lt->tamanho = n;
    lt->quantidade = 0;
}

void iniciaEstrutura (struct Estrutura *et, int n, int id)
{
    et->itens = (int *) malloc(sizeof(int) * n);
    et->inicio = -1;
    et->fim = -1;
    et->tamanho = n;
    et->id = id;
    et->quantidade = 0;

}

void inserirEstrutura(struct Lista *lt, struct Estrutura et)
{
    if (lt->quantidade == 0)
    {
        lt->itens[0] = et;
    }
    else
    {
        int i = 0;
        while (i < lt->quantidade) i++;

        lt->itens[i] = et;
    }

    lt->quantidade++;
}

void mostrar(struct Estrutura et)
{
    if (et.id == 0)
    {
        for (int i = 0; i < et.quantidade; i++)
        {
            if (i != et.quantidade - 1) printf("%d ", et.itens[i]);

            else printf("%d\n", et.itens[i]);
        }
    }
    else if (et.id == 1)
    {
        for (int i = et.inicio; i <= et.fim && et.quantidade != 0; i++)
        {
            if (et.fim  != i) printf("%d ", et.itens[i]);
            else printf("%d\n", et.itens[i]);
        }
    }
    else if (et.id == 2)
    {
        for (int i = 0; i <= et.fim; i++)
        {
            if (et.fim  != i) printf("%d ", et.itens[i]);
            else printf("%d\n", et.itens[i]);
        }
    }
    else
    {
        if (et.quantidade == 0) return;
        int i = et.inicio;

        while (i != et.fim)
        {
            printf("%d ", et.itens[i]);

            i = (i + 1) % et.tamanho;
        }
        printf("%d\n", et.itens[et.fim]);
    }
}

void deslocaDir (struct Estrutura *l, int i)
{
    int k;
    for (k = l->quantidade - 1; k >= i; k--)
        l->itens[k+1] = l->itens[k]; // deslocando os elementos para a direita
}

void inserir(struct Estrutura *et, int chave)
{
    if (et->id == 0) // LISTA
    {
        if (et->quantidade == et->tamanho) return;

        if (et->quantidade == 0)
        {
            et->itens[0] = chave;
            et->quantidade++;
        }
        else
        {
            int i = 0;

            while(i < et->quantidade && et->itens[i] < chave) i++;

            if (et->itens[i] == chave) return;

            deslocaDir(et, i);

            et->itens[i] = chave;
            et->quantidade++;
        }
    }
    else if (et->id == 1) // FILA
    {
        if (et->fim != et->tamanho - 1)
        {
            if (et->inicio == -1 && et->fim == -1) et->inicio++;

            et->fim++;
            et->itens[et->fim] = chave;
            et->quantidade++;
        }
    }
    else if (et->id == 2) // PILHA
    {
        if (et->fim < et->tamanho - 1)
        {
            et->fim++;
            et->itens[et->fim] = chave;
            et->quantidade++;
        }
    }
    else if (et->id == 3) // CIRCULAR
    {

        if (et->quantidade == et->tamanho - 1) return;

        et->fim = (et->fim + 1) % et->tamanho;

        if (et->quantidade == 0)
        {
            et->inicio = (et->inicio + 1) % et->tamanho;
            et->itens[et->inicio] = chave;
        }
        else
        {
            et->itens[et->fim] = chave;
        }

        et->quantidade++;
    }
}

void deslocaEsq (struct Estrutura *l, int i)
{
    int k;
    for (k = i;k < l->quantidade; k++)
    {
        l->itens[k] = l->itens[k+1];
    }
}

int checkVazia(struct Estrutura *f)
{
    if (f->inicio != -1 && f->inicio > f->fim) return 1;

    return 0;
}

void iniciaFilaC(struct Estrutura *fila)
{
	fila->inicio = -1;
	fila->fim = -1;
	fila->quantidade = 0;
}

void remover(struct Estrutura *et, int chave)
{
    if (et->id == 0) // LES
    {
        int i = 0;

        while (i < et->quantidade && et->itens[i] != chave) i++;

        if (i == et->quantidade && et->itens[i] != chave) return;

        printf("REMOVIDO: %d\n", et->itens[i]);

        deslocaEsq(et, i);
        et->quantidade--;

    }
    else if (et->id == 1) // FILA
    {
        if (et->inicio != -1 && et->fim != -1)
        {
            printf("REMOVIDO: %d\n", et->itens[et->inicio]);
            et->inicio++;
        }

        if (checkVazia(et)) iniciaEstrutura(et, et->tamanho, et->id);

    }
    else if (et->id == 2) // PILHA
    {
        if (et->quantidade != 0)
        {
            printf("REMOVIDO: %d\n", et->itens[et->fim]);

            et->quantidade--;
            et->fim--;
        }
    }
    else if (et->id == 3) // CIRCULAR
    {
        if (et->inicio != -1)
        {
            printf("REMOVIDO: %d\n", et->itens[et->inicio]);

            et->inicio = (et->inicio + 1) % et->tamanho;

            et->quantidade--;

            if (et->quantidade == 0) iniciaFilaC(et);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Lista lista;
    iniciaLista(&lista, n);

    int tamanho;
    char nome[100];

    for (int i = 0; i < n; i++)
    {
        struct Estrutura estrutura;

        scanf("\n%s", nome);
        scanf("%d", &tamanho);

        if (strcmp(nome, "LES") == 0)
        {
            iniciaEstrutura(&estrutura, tamanho, 0);
            inserirEstrutura(&lista, estrutura);
        }
        else if (strcmp(nome, "FILA") == 0)
        {
            iniciaEstrutura(&estrutura, tamanho, 1);
            inserirEstrutura(&lista, estrutura);
        }
        else if (strcmp(nome, "PILHA") == 0)
        {
            iniciaEstrutura(&estrutura, tamanho, 2);
            inserirEstrutura(&lista, estrutura);
        }
        else if (strcmp(nome, "CIRCULAR") == 0)
        {
            iniciaEstrutura(&estrutura, tamanho, 3);
            inserirEstrutura(&lista, estrutura);
        }
    }

    int x, pos;
    char op;

    while (scanf("%d %c", &pos ,&op) != EOF)
    {
        if (op == 'I')
        {
            scanf("%d", &x);

            inserir(&lista.itens[pos], x);
        }
        else if (op == 'M')
        {
            mostrar(lista.itens[pos]);
        }
        else if (op == 'R')
        {
            if (lista.itens[pos].id == 0) // caso a estrutura seja uma lista
            {
                scanf("%d", &x);

                remover(&lista.itens[pos], x);
            }
            else
            {
                remover(&lista.itens[pos], 0);
            }
        }
    }

    return 0;
}
