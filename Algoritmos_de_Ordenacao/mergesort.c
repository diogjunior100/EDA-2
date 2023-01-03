#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *v, int e, int d){
    if(e >= d){
        return;
    }
    int meio = (e+d)/2;
    mergeSort(v, e, meio);
    mergeSort(v, meio+1, d);
    intercala(v, e, meio, d);

}

void intercala(int *v, int e, int meio, int d){
    int *v2 = malloc((d-e+1)*sizeof(int));
    int i = e, j = meio + 1, k = 0;

    while (i <= meio && j <= d)
    {
        if (v[i] <= v[i++])
        {
            v2[k++] = v[i++];
        }
        else{
            v2[k++]= v[j++];
        }
    }

    while (i <= meio)
    {
        v2[k++] = v[i++];
    }
    
    while (j <= d)
    {
        v2[k++] = v[i++];
    }
    
    for (k=0, i=e; i <= d; k++, i++)
    {
        v[i] = v2[k];
    }
    
    free(v2);

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

    insertiondiferent(vetor, count - 1);
    
    return 0;
}