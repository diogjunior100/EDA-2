#include <stdio.h>
#include <stdlib.h>

typedef struct informacoes
{

    int qnt;
    char caracter;
    int pos;

} info;

void mergePos(info V[], int l, int meio, int r)
{
    info *vetorTemp = malloc(sizeof(info) * (r - l + 1));
    int i = l, j = meio + 1, k = 0;

    while (i <= meio && j <= r)
    {
        if (V[i].pos >= V[j].pos)
            vetorTemp[k++] = V[i++];
        else
            vetorTemp[k++] = V[j++];
    }

    while (i <= meio)
        vetorTemp[k++] = V[i++];
    while (j <= r)
        vetorTemp[k++] = V[j++];

    k = 0;
    for (i = l; i <= r; i++)
        V[i] = vetorTemp[k++];
    free(vetorTemp);
}

void mergeSortPos(info V[], int l, int r)
{
    if (l >= r)
        return;
    int meio = (l + r) / 2;
    mergeSortPos(V, l, meio);
    mergeSortPos(V, meio + 1, r);
    mergePos(V, l, meio, r);
}

void mergeSize(info V[], int l, int meio, int r)
{
    info *vetorTemp = malloc(sizeof(info) * (r - l + 1));
    int i = l, j = meio + 1, k = 0;

    while (i <= meio && j <= r)
    {
        if (V[i].qnt <= V[j].qnt)
            vetorTemp[k++] = V[i++];
        else
            vetorTemp[k++] = V[j++];
    }

    while (i <= meio)
        vetorTemp[k++] = V[i++];
    while (j <= r)
        vetorTemp[k++] = V[j++];

    k = 0;
    for (i = l; i <= r; i++)
        V[i] = vetorTemp[k++];
    free(vetorTemp);
}

void mergeSortSize(info V[], int l, int r)
{
    if (l >= r)
        return;
    int meio = (l + r) / 2;
    mergeSortSize(V, l, meio);
    mergeSortSize(V, meio + 1, r);
    mergeSize(V, l, meio, r);
}

int main()
{
    int i = 0;

    char *entrada = malloc(sizeof(char) * 100001);

    info *stc = malloc(sizeof(info) * 100001);

    scanf("%s", entrada);

    char atual = entrada[i];
    int contador = 1, seqIni = 0, qntEnt = 0;
    i++;
    while (entrada[i] != '\0')
    {
        if (entrada[i] == atual)
        {
            contador++;
        }
        else
        {
            stc[qntEnt].caracter = atual;
            stc[qntEnt].pos = seqIni;
            stc[qntEnt].qnt = contador;
            qntEnt++;
            contador = 1;
            atual = entrada[i];
            seqIni = i;
        }
        i++;
    }
    stc[qntEnt].caracter = atual;
    stc[qntEnt].pos = seqIni;
    stc[qntEnt].qnt = contador;
    qntEnt++;

    mergeSortPos(stc, 0, qntEnt - 1);
    mergeSortSize(stc, 0, qntEnt - 1);

    for (int i = qntEnt - 1; i >= 0; i--)
        printf("%d %c %d\n", stc[i].qnt, stc[i].caracter, stc[i].pos);

    return 0;
}