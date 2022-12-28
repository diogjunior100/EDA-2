#include <stdio.h>

typedef int Item;

void selectionsort(int *v, int l, int r){
    int min;

    for (int i = l; i < r; i++)
    {
        int min = i;

        for (int j = i+1; j < r; j++)
        {
            if(v[j] < v[min]) min = j;
        }

        //exch(v[min], v[l]);
        int t = v[min];
        v[min] = v[i];
        v[i] = t;    
    }

    for (int i = 0; i < r; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");
    
}

void selectiondiferent(int *v, int n){
    for (int i = 0; i < n -1; ++i){
        int min = i;

        for (int j = i + 1; j < n; ++j){
            if (v[j] < v[min]){
                min = j;
            } 
        }
        
        int x = v[i];
        v[i] = v[min];
        v[min] = x;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");
    
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
    
    //selectionsort(vetor,l, count - 1);

    selectiondiferent(vetor,count - 1);
    
    return 0;
}