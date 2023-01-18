#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char matriz[109][20];
int size = 0; 

int hash(char *k)
{
    int h = 0;
    for (int i = 0; k[i] != '\0'; i++)
        h += k[i] * (i + 1LL);
    return (h * 19) % 101;
}

int busca(char *s)
{
    int h = hash(s);
    for (int j = 0; j < 20; j++)
    {
        int i = (h + j * j + 23LL * j) % 101;
        if (strcmp(matriz[i], s) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void inserir(char *s)
{
    if (busca(s))
        return;

    int h = hash(s);
    for (int j = 0; j < 20; j++)
    {
        int i = (h + j * j + 23LL * j) % 101;
        if (*matriz[i] == '\0')
        {
            strcpy(matriz[i], s);
            size++;
            break;
        }
    }
}

void deletar(char *s)
{
    int h = hash(s);
    for (int j = 0; j < 20; j++)
    {
        int i = (h + j * j + 23LL * j) % 101;

        if (strcmp(matriz[i], s) == 0)
        {
            *matriz[i] = '\0';
            size--;
        }
    }
}

int main()
{
    int t;

    scanf(" %d", &t);
    while (t--)
    {
        for (int i = 0; i < 101; i++)
        {
            *matriz[i] = '\0';
        }

        size = 0;
        int n;

        scanf(" %d", &n);
        char m[4], s[16];

        while (n--)
        {
            scanf(" %s:%s", m, s);
            if (m[0] == 'A')
            {
                inserir(s);
            }
            else{
                deletar(s);
            }
        }

        printf("%d\n", size);
        for (int i = 0; i < 101; i++)
        {
            if (*matriz[i] != '\0')
            {
                printf("%d:%s\n", i, matriz[i]);
            }
        }
    }

    return 0;
}