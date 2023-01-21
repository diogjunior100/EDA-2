#include <stdio.h>
#include <stdlib.h>

#define TAM 76000000
        
int hash(int x){
    return x%76000000;
}

int main()
{
    int N;
    int i, *vetor = calloc(sizeof(long long int), TAM);
    int num, count;

    scanf("%d", &N);

    for (i = 0; i < N; ++i){
        scanf("%d", &num);
        vetor[hash(num)] = num;
        
        while (vetor[count] != 0){
            count = count + 1;
            if (count == TAM) {
                count = 0;
            }
        }
        vetor[count] = num;
    }

    while (scanf("%d", &num) != EOF){
        int h = hash(num);
        

        if (vetor[h] == num){
            printf("sim\n");
        }
        else{
            printf("nao\n");
        }
        
    }
    
     
    return 0;
}
