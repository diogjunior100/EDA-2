#include <stdio.h>
#include <stdlib.h>

#define tam 760000

int hash(int x){
    return x%760000;
}

int main()
{
    int N;
    int i, *vetor = calloc(sizeof(long long int), tam);
    int num, vantigo, cout = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &num);
        vetor[hash(num)] = num;
    }

    while (scanf("%d", &num) != EOF)
    {
        int h = hash(num);
        cout++;

        if (cout == tam)
        {
            return 0;
        }
        

        if (vetor[h] == num)
        {
            printf("sim\n");
        }
        else
        {
            printf("nao\n");
        }
        
    }
    
     
    return 0;
}
