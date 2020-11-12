#include <stdio.h>
#include <stdlib.h>

struct Pilha
{
    struct Item *topo;
};

struct Item
{
    struct Item *anterior;
    int dado;
};

struct Pilha * criaPilha();
struct Item * criaItem(int);

void empilhar(struct Pilha *, int dado);
void desempilhar(struct Pilha*);
void mostrar(struct Pilha*);
void destruirPilha(struct Pilha*);

int main()
{
    int x;
    char op;
    struct Pilha *pilha = criaPilha();

    while(scanf("\n%c", &op) != EOF)
    {
        if (op == 'E')
        {
            scanf("%d", &x);
            // Empilhar
            empilhar(pilha, x);
        }
        else if (op == 'D')
        {
            // Desempilhar
            desempilhar(pilha);
        }
        else if(op == 'M')
        {
            // Mostrar
            mostrar(pilha);
        }
    }

    // Destruir Pilha
    destruirPilha(pilha);

    return 0;
}

struct Pilha * criaPilha()
{
    struct Pilha *pilha = (struct Pilha*) malloc(sizeof(struct Pilha));
    if (pilha != NULL)
    {
        pilha->topo = NULL;
    }
    return pilha;
}

struct Item * criaItem(int dado)
{
    struct Item *item = (struct Item*) malloc(sizeof(struct Item));
    if (item != NULL)
    {
        item->dado = dado;
        item->anterior = NULL;
    }
    return item;
}

void empilhar(struct Pilha *p, int dado)
{
    struct Item *novo = criaItem(dado);
    novo->anterior = p->topo;
    p->topo = novo;
}

void desempilhar(struct Pilha* p)
{
    if (p->topo != NULL)
    {
        printf("[%d]\n", p->topo->dado);
        struct Item *atual = p->topo;
        p->topo = p->topo->anterior;
        free(atual);
    }
    else printf("Underflow Error: Pilha Vazia.\n");
}

void mostrar(struct Pilha* p)
{
    if (p->topo != NULL)
    {
        struct Item *atual = p->topo;

        while (atual != NULL)
        {
            if (atual->anterior == NULL) printf("%d\n", atual->dado);
            else printf("%d ", atual->dado);
            atual = atual->anterior;
        }
    }
    else printf("Underflow Error: Pilha Vazia.\n");
}

void destruirPilha(struct Pilha *p)
{
    struct Item *atual = p->topo;
    while(p->topo != NULL)
    {
        atual = p->topo;
        p->topo = p->topo->anterior;
        free(atual);
    }
    free(p);
}