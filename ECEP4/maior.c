#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *esq;
    struct Node *dir;
};

typedef struct Node *Arvore;

Arvore * criaArvore()
{
    Arvore *raiz = (Arvore *) malloc(sizeof(Arvore));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

struct Node* criaNode(int info)
{
    struct Node *novo = (struct Node *) malloc(sizeof(struct Node));

    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

void inserir(Arvore *raiz, int valor)
{
    if (raiz == NULL)
        return;

    struct Node *novo = criaNode(valor);

    if (*raiz == NULL)
        *raiz = novo;

    else
    {
        struct Node *atual = *raiz;
        struct Node *anterior = NULL;

        while (atual != NULL)
        {
            anterior = atual;

            if (valor >= atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if (valor >= anterior->info)
            anterior->dir = novo;
        else
            anterior->esq = novo;
    }
}

int maior(Arvore *raiz)
{
    int maior;
    struct Node *atual = *raiz;

    while(atual->dir != NULL)
    {
        atual = atual->dir;
    }

    return atual->info;
}

void lerArvore(Arvore *arvore, int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        inserir(arvore, x);
    }
}

int main()
{
    int n;
    Arvore *arvore = criaArvore();

    scanf("%d", &n);

    lerArvore(arvore, n);

    printf("%d\n",maior(arvore));

    return 0;
}