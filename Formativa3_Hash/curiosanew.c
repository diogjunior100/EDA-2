#include <stdio.h>
#include <stdlib.h>

int main()
{

    int qtd, num, notas[1001];
    scanf(" %d", &qtd);

    //notas = malloc(1001);

    for (int i = 0; i <= 1000; i++)
    {
        notas[i] = 0;
    }

    for (int i = 0; i < qtd; i++)
    {
        scanf(" %d", &num);
        notas[num]++;
    }

    int maior = 0;

    for (int i = 0; i <= 1000; i++)
    {
        if (notas[maior] <= notas[i])
            maior = i;
    }

    printf("%d\n", maior);
    return 0;
}