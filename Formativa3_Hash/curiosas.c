#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd, valor, notas[101];
    int maior = 0;
    //notas = malloc(sizeof(int)*101);

    scanf(" %d", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        scanf(" %d", valor);
        notas[valor]++;
    }
    
    for (int i = 0; i <= 100; i++)
    {
        if (notas[maior] <= notas[i])
        {
            maior = i;
        }
    }

    printf("%d\n", maior);

    return 0;
}
