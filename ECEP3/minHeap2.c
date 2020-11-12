#include <stdio.h>
#include <stdlib.h>

int * criaVetor(int n)
{
    int *v = (int *) malloc(n * sizeof(int));
    return v;
}

void imprimeVetor(int *v, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[tamanho - 1]);
}

void heapifyBaixoCima(int *v, int index){
    int temp;
    int i = (index-1)/2;

    if(v[i] >v[index]){
        //swap and recursive call
        temp = v[i];
        v[i] = v[index];
        v[index] = temp;
        heapifyBaixoCima(v, i);
    }
}

void inserir(int *v, int j, int x){
    v[j] = x;
    heapifyBaixoCima(v, j);
}


int buscar(int *v, int j, int x)
{
   for (int i = 0; i <= j; i++)
   {
       if (v[i] == x) return i;
   }
}

void heapifyCimaBaixo(int *v, int j, int i)
{
    int esq = i * 2 + 1;
    int dir = i * 2 + 2;
    int min;
    int temp;

    if(esq >= j || esq <0)
        esq = -1;
    if(dir >= j || dir <0)
        dir = -1;

    if(esq != -1 && v[esq] < v[i])
        min = esq;
    else
        min = i;
    if(dir != -1 && v[dir] < v[min])
        min = dir;

    if(min != i){
        temp = v[min];
        v[min] = v[i];
        v[i] = temp;

        // recursive  call
        heapifyCimaBaixo(v, j, min);
    }
}

void remover(int *v, int j, int x)
{
    int pop;

    pop = buscar(v, j, x);

    if (pop != j)
        v[pop] = v[j - 1];

    heapifyCimaBaixo(v, j, pop);
}

int main()
{
    int n, op, x, j = 0;
    scanf("%d", &n);

    int *v = criaVetor(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            inserir(v, j, x);
            j++;
        }
        else if (op == 2)
        {
            scanf("%d", &x);
            remover(v, j, x);
            j--;
        }
        else if (op == 3)
        {
            printf("%d\n", v[0]);
        }
    }
    free(v);
    return 0;
}