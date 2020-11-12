#include <stdlib.h>
#include <stdio.h>

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

            if (valor == atual->info)
                return;

            if (valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if (valor > anterior->info)
            anterior->dir = novo;
        else
            anterior->esq = novo;
    }
}

int altura(Arvore *raiz)
{
    if (raiz == NULL || *raiz == NULL)
        return 0;

    int alt_esq = altura(&(*raiz)->esq);
    int alt_dir = altura(&(*raiz)->dir);

    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

int main()
{
    int n, x;
    Arvore *arvore = criaArvore();

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        inserir(arvore, x);
    }

    printf("%d\n", altura(arvore) - 1);

    return 0;
}