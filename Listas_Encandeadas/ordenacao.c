#include <stdio.h>
#include <stdlib.h>


typedef int Item;


void selectionsort(int *vetor, int r) {
   int min;

   for(int i = 0; i < r - 1; i++) 
   {
      min = i;

      for(int j = i + 1; j < r; j++) 
      {
        if (vetor[j] < vetor[min])
        {
            min = j;
        }
      }
      int aux = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = aux;
   }

   for (int a = 1; a < r; a++)
   {
        printf("%d ", vetor[a]);
   }

   printf("\n");
   
}
    

int main()
{
    int *vetor;
    int count = 0, l = 0;
    int a = 1;

    vetor = malloc(1001);

    while (a != EOF)
    {
         a = scanf("%d", &vetor[count++]);
    }

    selectionsort(vetor, count);
    
    return 0;
}