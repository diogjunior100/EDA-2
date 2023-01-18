#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define less(a,b) (a.value == b.value ? a.key > b.key : a.value > b.value)
//#define less(a,b) if(a.value == b.value) a.key>b.key; else a.value>b.value;
#define exch(a, b) {Item t; t=a, a=b; b=t; }
#define cmpexch(a,b) {if(less(b,a)) exch(a,b);}

typedef struct 
{
    int key, value;
} Item;

int particiona(Item *v, int l, int r)
{
    Item pivo = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], pivo))
        {
            exch(v[k], v[j]);
            j++;
        }
    exch(v[j], v[r]);
    return j;
}

void quicksort(Item *v, int l, int r)
{
    if (r <= l)
        return;

    cmpexch(v[(l + r) / 2], v[r]);
    cmpexch(v[l], v[(l + r) / 2]);
    cmpexch(v[r], v[(l + r) / 2]);

    int m = particiona(v, l, r);

    quicksort(v, l, m - 1);
    quicksort(v, m + 1, r);
}

int pn = 0, sen = 0, dfn = 0, den = 0;
Item pr[91], sn[901], dfr[9001], des[90001];

int main()
{
    long long s,f,e;
    int x,l = 0, i;
    long long valido = 0, invalido = 0, total = 0;
    

    scanf(" %lld %lld %lld", &s, &f, &e);

    while (scanf("%d%n", &x, &l) == 1)
    {
        if (x < 0)
        {
            invalido++;
            continue;
        }

        switch (l)
        {
        case 3:
            pr[x - 10].key = x;
            pr[x - 10].value++;
            total++;
            break;
        
        case 4:
            sn[x - 100].key = x;
            sn[x - 100].value++;
            break;

        case 5:
            dfr[x - 1000].key = x;
            dfr[x - 1000].value++;
            break;

        default:
            des[x - 10000].key = x;
            des[x - 10000].value++;
            break;
        }
        valido++;
    }

    for (i = 0; i < 91; i++)
    {
        if (pr[i].value)
        {
            pr[pn++] = pr[i];
        }
        
    }

    for (i = 0; i < 901; i++)
    {
        if (sn[i].value)
        {
            sn[sen++] = sn[i];
        }
        
    }

    for (i = 0; i < 9001; i++)
    {
        if (dfr[i].value)
        {
            dfr[dfn++] = dfr[i];
        }
        
    }
    
    for (i = 0; i < 90001; i++)
    {
        if (des[i].value)
        {
            des[den++] = des[i];
        }    
    }
    
    printf("%lld %lld\n", valido, invalido);

    quicksort(pr, 0, pn - 1);
    quicksort(sn, 0, sen - 1);
    quicksort(dfr, 0, dfn - 1);
    quicksort(des, 0, den - 1);

    if ((double)pr[0].value / total >= .51)
    {
        printf("%d\n", pr[0].key);
    }
    else
    {
        printf("Segundo turno\n");
    }

    for (i = 0; i < s; i++)
    {
        printf("%d%c", sn[i].key, " \n"[i == s - 1]);
    }

    for (i = 0; i < f; i++)
    {
        printf("%d%c", dfr[i].key, " \n"[i == f - 1]);
    }
    
    for (i = 0; i < e; i++)
    {
        printf("%d%c", des[i].key, " \n"[i == e - 1]);
    }
    
    
    return 0;
}
