#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) <= (B))

void intercala(int *v, int e, int meio, int d){

    int *vtemp = malloc(sizeof(int)*(d-e+1));
    
    int i = e, j = meio + 1, k = 0;

    while (i <= meio && j <= d)
    {
        if (less(v[i],v[j]))
        {
            vtemp[k++] = v[i++];
        }
        else{
            vtemp[k++]= v[j++];
        }
    }

    while (i <= meio)
    {
        vtemp[k++] = v[i++];
    }
    
    while (j <= d)
    {
        vtemp[k++] = v[j++];
    }
    
    k = 0;
    for (i = e; i <=d; i++)
    {
        v[i] = vtemp[k++];
    }
    
    free(vtemp);

}

void mergeSort(int *v, int e, int d){
    if(e >= d){
        return;
    }
    int meio = (e+d)/2;
    mergeSort(v, e, meio);
    mergeSort(v, meio+1, d);
    intercala(v, e, meio, d);

}



int main()
{
    int vetor[100000];
    int count = 0, l = 0;

   while (scanf("%d", &vetor[count]) != EOF)
    {
        //a = scanf("%d", &vetor[count]);
        count++;
    }
    
    mergeSort(vetor, l, count - 1);

    for (int i = 0; i < count ; i++)
    {
        printf("%d ", vetor[i]);
    }
    
    printf("\n");
    
    return 0;
}