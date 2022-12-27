#include <stdio.h>

typedef int Item;

void insertion(int *v, int l, int r){

    for(int i = l + 1; i< r; i++){
        for (int j = i; j > l; j--)
        {
            if(v[j-1] > v[j]){
                int aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }   
    }

    for (int i = 0; i < r; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");
    
}

void insertiondiferent(int *v, int n){
    int elem, i, j;

    for (i = 1; i < n; i++)
    {
        elem = v[i];

        for (j = i - 1; j >= 0 && v[j] > elem; j--)
        {
            v[j+1] = v[j];
        }
        
        v[i+1] = elem;
    }
    
}


int main()
{
    Item vetor[1001];
    int count = 0, l = 0;
    int a = 1;

    while (a != EOF)
    {
        a = scanf("%d", &vetor[count++]);
    }
    
    insertion(vetor,l, count - 1);
    
    return 0;
}
