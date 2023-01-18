#include <stdio.h>
#include <stdlib.h>

void preenche(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
        scanf("%d", &vet[i]);
}

int *intercala2(int *v1, int l1, int r1, int *v2, int l2, int r2)
{
    int *vetorTemp = malloc(sizeof(int) * (r1 + r2));
    int i = 0;

    while (l1 < r1 && l2 < r2)
    {
        if (v1[l1] < v2[l2])
            vetorTemp[i++] = v1[l1++];
        else
            vetorTemp[i++] = v2[l2++];
    }

    while (l1 < r1)
    {
        vetorTemp[i++] = v1[l1++];
    }

    while (l2 < r2)
    {
        vetorTemp[i++] = v2[l2++];
    }

    return vetorTemp;
}

int *intercala4(int *v1, int l1, int r1, int *v2, int l2, int r2, int *v3, int l3, int r3, int *v4, int l4, int r4)
{
    int *vetorTemp1, *vetorTemp2;
    vetorTemp1 = intercala2(v1, l1, r1, v2, l2, r2);
    vetorTemp2 = intercala2(v3, l3, r3, v4, l4, r4);
    return intercala2(vetorTemp1, 0, r1 + r2, vetorTemp2, 0, r3 + r4);
}

int *intercala8(int *v1, int l1, int r1, int *v2, int l2, int r2, int *v3, int l3, int r3, int *v4, int l4, int r4, int *v5, int l5, int r5, int *v6, int l6, int r6, int *v7, int l7, int r7, int *v8, int l8, int r8)
{
    int *vetorTemp1, *vetorTemp2;
    vetorTemp1 = intercala4(v1, l1, r1, v2, l2, r2, v3, l3, r3, v4, l4, r4);
    vetorTemp2 = intercala4(v5, l5, r5, v6, l6, r6, v7, l7, r7, v8, l8, r8);
    return intercala2(vetorTemp1, 0, r1 + r2 + r3 + r4, vetorTemp2, 0, r5 + r6 + r7 + r8);
}

int main()
{

    int qnt1, qnt2, qnt3, qnt4, qnt5, qnt6, qnt7, qnt8;
    int qntF = 0;
    int *vet1, *vet2, *vet3, *vet4, *vet5, *vet6, *vet7, *vet8;
    int *vetFinal;

    scanf("%d", &qnt1);
    qntF = qntF + qnt1;
    vet1 = malloc(sizeof(int) * qnt1);
    preenche(vet1, qnt1);

    scanf("%d", &qnt2);
    qntF = qntF + qnt2;
    vet2 = malloc(sizeof(int) * qnt2);
    preenche(vet2, qnt2);

    scanf("%d", &qnt3);
    qntF = qntF + qnt3;
    vet3 = malloc(sizeof(int) * qnt3);
    preenche(vet3, qnt3);

    scanf("%d", &qnt4);
    qntF = qntF + qnt4;
    vet4 = malloc(sizeof(int) * qnt4);
    preenche(vet4, qnt4);

    scanf("%d", &qnt5);
    qntF = qntF + qnt5;
    vet5 = malloc(sizeof(int) * qnt5);
    preenche(vet5, qnt5);

    scanf("%d", &qnt6);
    qntF = qntF + qnt6;
    vet6 = malloc(sizeof(int) * qnt6);
    preenche(vet6, qnt6);

    scanf("%d", &qnt7);
    qntF = qntF + qnt7;
    vet7 = malloc(sizeof(int) * qnt7);
    preenche(vet7, qnt7);

    scanf("%d", &qnt8);
    qntF = qntF + qnt8;
    vet8 = malloc(sizeof(int) * qnt8);
    preenche(vet8, qnt8);

    vetFinal = intercala8(vet1, 0, qnt1, vet2, 0, qnt2, vet3, 0, qnt3, vet4, 0, qnt4, vet5, 0, qnt5, vet6, 0, qnt6, vet7, 0, qnt7, vet8, 0, qnt8);

    for (int i = 0; i < qntF; i++)
    {
        printf("%d ", vetFinal[i]);
    }
    printf("\n");

    return 0;
}