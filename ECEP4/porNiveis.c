#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info, nivel;
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

void lerArvore(Arvore *arvore, int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        inserir(arvore, x);
    }
}

void niveis(Arvore *raiz, int nivel)
{
    if (raiz == NULL) return;

    if (*raiz == NULL) return;

    (*raiz)->nivel = nivel;

    niveis(&(*raiz)->esq, nivel + 1);
    niveis(&(*raiz)->dir, nivel + 1);
}

void imprimirNivel(Arvore *raiz, int k)
{
    if (raiz == NULL)
        return;

    if (*raiz != NULL)
    {
        if ((*raiz)->nivel == k)
            printf("%d\n", (*raiz)->info);

        imprimirNivel(&((*raiz)->esq), k);
        imprimirNivel(&((*raiz)->dir), k);
    }
}

void imprimirElementos(Arvore *raiz, int h)
{
    for (int i = 0; i < h; i++)
    {
        imprimirNivel(raiz, i);
    }
}

int main()
{
    int n, h;
    Arvore *arvore = criaArvore();

    scanf("%d", &n);
    lerArvore(arvore, n);
    h = altura(arvore);
    niveis(arvore, 0);
    imprimirElementos(arvore, h);

    return 0;
}