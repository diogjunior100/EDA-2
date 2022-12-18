#include <stdio.h>
#define key(A)(A);
#define less(A,B);
#define cmpexch(A,B);
#define exch(A,B);

typedef int Item;

void ordena(int *vetor, int l, int r){
    int aux;
    for (int i = l; i < r; i++)
    {
        for (int b = l + 1; b < r; b++)
        {
            //cmpexch(vetor[b], vetor[b+1]);
            if (vetor[b] < vetor[b-1])
            {
                aux = vetor[b];
                vetor[b] = vetor[b-1];
                vetor[b-1] = aux; 
            }
        }
    }
    
    for (int a = 0; a < r; a++)
    {
        printf("%d ", vetor[a]);
    }

    printf("\n");
    
}

int main()
{
    int vetor[1001];
    int count = 0, l = 0;
    int a = 1;

    while (a != EOF)
    {
        a = scanf("%d", &vetor[count++]);
    }

    ordena(vetor, l, count - 1);
    
    return 0;
}