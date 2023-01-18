#include <stdio.h>
#include <stdlib.h>

typedef struct informacoes
{
    int tam;
    char caractere;
    int pos;

}info;

void mergeTam(info v[], int e, int meio, int d)
{
    info *vetorTemp = malloc(sizeof(info) * (d - e + 1));
    int i = e, j = meio + 1, k = 0;

    while (i <= meio && j <= d)
    {
        if (v[i].tam <= v[j].tam)
            vetorTemp[k++] = v[i++];
        else
            vetorTemp[k++] = v[j++];
    }

    while (i <= meio)
    {
        vetorTemp[k++] = v[i++];
    }
    while (j <= d)
    {
        vetorTemp[k++] = v[j++];
    }

    k = 0;
    for (i = e; i <= d; i++){
        v[i] = vetorTemp[k++];
    }
    free(vetorTemp);
}

void mergeSortTam(info v[], int e, int d)
{
    if (e >= d){
        return;
    }

    int meio = (e + d) / 2;
    mergeSortSize(v, e, meio);
    mergeSortSize(v, meio + 1, d);
    mergeSize(v, e, meio, d);
}

void mergePos(info v[], int e, int meio, int d)
{
    info *vetorTemp = malloc(sizeof(info) * (d - e + 1));
    int i = e, j = meio + 1, k = 0;

    while (i <= meio && j <= d)
    {
        if (v[i].pos >= v[j].pos)
            vetorTemp[k++] = v[i++];
        else
            vetorTemp[k++] = v[j++];
    }

    while (i <= meio)
    {
        vetorTemp[k++] = v[i++];
    }

    while (j <= d)
    {
        vetorTemp[k++] = v[j++];
    }

    k = 0;
    for (i = e; i <= d; i++)
    {
        v[i] = vetorTemp[k++];
    }

    free(vetorTemp);
}

void mergeSortPos(info v[], int e, int d)
{
    if (e >= d){
        return;
    }

    int meio = (e + d) / 2;
    mergeSortPos(v, e, meio);
    mergeSortPos(v, meio + 1, d);
    intercalaPos(v, e, meio, d);
}

int main()
{
    int i = 0, count = 1, seqIni = 0, qntEnt = 0;
    char *entrada, letra;

    entrada = malloc(sizeof(char) * 100001);

    info *stc = malloc(sizeof(stc) * 100001);

    scanf("%s", entrada);

    letra = entrada[i];
    i++;

    while (entrada[i] != '\0')
    {
        if (entrada[i] == letra)
        {
            count++;
        }
        else
        {
            stc[qntEnt].caractere = letra;
            stc[qntEnt].pos = seqIni;
            stc[qntEnt].tam = count;
            qntEnt++;
            count = 1;
            letra = entrada[i];
            seqIni = i;
        }
        i++;
    }
    stc[qntEnt].caractere = letra;
    stc[qntEnt].pos = seqIni;
    stc[qntEnt].tam = count;
    qntEnt;

    mergeSortPos(stc, 0, qntEnt - 1);
    mergeSortTam(stc, 0, qntEnt - 1);
    
    for(int i = qntEnt - 1; i >= 0; i--){
        printf("%d %c %d\n", stc[i].tam, stc[i].caractere, stc[i].pos);
    }

    return 0;
}
