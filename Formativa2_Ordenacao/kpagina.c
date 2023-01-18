#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define exch(A,B) {int t; t=A, A=B; B=t; }
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}


int separa(int *v, int l, int r)
{
    int i = l - 1, j = r;
    int c = v[r];

    for (;;)
    {
        while (less(v[++i], c))
        {
            ;
        }

        while (less(c, v[--j]))
        {
            if (i == j)
            {
                break;
            }
        }

        if (i >= j)
        {
            break;
        }

        exch(v[i], v[j]);
    }

    exch(v[i], v[r]);
    return i;
}
void quickSelect(int *v, int l, int r, int p)
{
    int j = separa(v, l, r);

    if (j == p)
    {
        return;
    }
    else if (j < p)
    {
        quickSelect(v, j + 1, r, p);
    }

    else
    {
        quickSelect(v, l, j - 1, p);
    }
}

void quickSort(int *v, int l, int r)
{
    if (l >= r)
        return;
    cmpexch(v[(l + r) / 2], v[r]);
    cmpexch(v[l], v[(l + r) / 2]);
    cmpexch(v[r], v[(l + r) / 2]);

    int j = separa(v, l, r);
    quickSort(v, l, j - 1);
    quickSort(v, j + 1, r);
}

int main()
{
    int n, p, x;
    int inicio, fim, fimP;
    scanf("%d %d %d", &n, &p, &x);

    int *vetor = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    inicio = x * p, fim = inicio + x;

    if (fim >= n)
    {
        fim = n - 1;
    }

    quickSelect(vetor, 0, n -1, inicio);
    quickSelect(vetor, inicio, n - 1, fim);
    quickSort(vetor, inicio, fim);

    if ((fim + 1) == n)
    {
        fimP = fim + 1;
    }
    else
    {
        fimP = fim;
    }
    
    for (int i = inicio; i < fimP; i++)
    {
        printf("%d\n", vetor[i]);
    }
    free(vetor);

    
    

    
    
    
    return 0;
}

