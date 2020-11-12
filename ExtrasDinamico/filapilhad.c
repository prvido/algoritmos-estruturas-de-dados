#include <stdio.h>
#include <stdlib.h>

struct Fila
{
    struct Item *inicio, *fim;
    int quantidade;
};

struct Pilha
{
    struct Item *topo;
    int quantidade;
};

struct Item
{
    int dado;
    struct Item *ref;
};

struct Fila * criaFila();
struct Pilha * criaPilha();
struct Item * criaItem(int);

void enfileirar(struct Fila *, int);
int desenfileirar(struct Fila *);
void empilhar(struct Pilha *, int);
void mostrar(struct Pilha*);

void igualar(struct Pilha*, struct Fila*);

void destroiFila(struct Fila *);
void destruirPilha(struct Pilha *);

int main()
{
    char op;
    int x;
    struct Fila *fila = criaFila();
    struct Pilha *pilha = criaPilha();

    while (scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &x);
            // Enfileirar
            enfileirar(fila, x);
        }
        else if (op == 'D')
        {
            // Desenfileirar
            desenfileirar(fila);
        }
        else if (op == 'M')
        {
            // Exibir
            mostrar(pilha);
        }
        else if (op == 'P')
        {
            // Igualar
            igualar(pilha, fila);
        }
    }
    destroiFila(fila);
    destruirPilha(pilha);
    return 0;
}

struct Fila * criaFila()
{
    struct Fila *fila = (struct Fila *) malloc(sizeof(struct Fila));
    if (fila != NULL)
    {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->quantidade = 0;
    }
    return fila;
}

struct Item * criaItem(int dado)
{
    struct Item *item = (struct Item *) malloc(sizeof(struct Item));
    if (item != NULL)
    {
        item->ref = NULL;
        item->dado = dado;
    }
    return item;
}

struct Pilha * criaPilha()
{
    struct Pilha *pilha = (struct Pilha*) malloc(sizeof(struct Pilha));
    if (pilha != NULL)
    {
        pilha->topo = NULL;
        pilha->quantidade = 0;
    }
    return pilha;
}

void enfileirar(struct Fila *f, int dado)
{
    struct Item *novo = criaItem(dado);

    if (f->inicio == NULL)
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->ref = novo;
    }

    f->fim = novo;

    f->quantidade++;
}

int desenfileirar(struct Fila *f)
{
    if (f->inicio != NULL)
    {
        struct Item *atual = f->inicio;

        f->inicio = f->inicio->ref;
        free(atual);

        if(f->inicio == NULL) f->fim == NULL;

        f->quantidade--;
    }
}

void mostrar(struct Pilha* p)
{
    if (p->topo != NULL)
    {
        struct Item *atual = p->topo;

        while (atual != NULL)
        {
            printf("%d\n", atual->dado);
            atual = atual->ref;
        }
    }
}

void destroiFila(struct Fila * f)
{
    if (f != NULL)
    {
        struct Item *atual;
        while(f->inicio != NULL)
        {
            atual = f->inicio;
            f->inicio = f->inicio->ref;
            free(atual);
        }
        free(f);
    }
}

void destruirPilha(struct Pilha *p)
{
    struct Item *atual = p->topo;
    while(p->topo != NULL)
    {
        atual = p->topo;
        p->topo = p->topo->ref;
        free(atual);
    }
    free(p);
}

void igualar(struct Pilha* p, struct Fila* f)
{
    int *v = (int *) malloc(f->quantidade * sizeof(int));

    if (p->topo != NULL)
    {
        destruirPilha(p);
        p = criaPilha();
    }

    int i = 0;

    struct Item *atual = f->inicio;

    while(atual != NULL)
    {
        v[i] = atual->dado;
        atual = atual->ref;
        i++;
    }

    for(i = f->quantidade - 1; i >= 0; i--)
    {
        struct Item *novo = criaItem(v[i]);
        empilhar(p, v[i]);
    }
    free(v);
}

void empilhar(struct Pilha *p, int dado)
{
    struct Item *novo = criaItem(dado);
    novo->ref = p->topo;
    p->topo = novo;
}