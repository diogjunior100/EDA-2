#include <stdio.h>

//1 - Norte (Soma +1 - Y)
//2 - Sul (Diminui -1 - Y)
//3 - Leste (Soma +1 - X)
//4 - Oeste (Diminui -1 - X)

int main() {
    int n, m, p;
    int pa_x = 1, pa_y = 1;
    int pb_x, pb_y, passos;

    scanf("%d %d %d", &n, &m, &p);
    
    pb_x = n;
    pb_y = m;
    for (passos = 1; passos <= p; passos++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if (a == 1) {
            pa_y++;
        } 
        else if (a == 2) 
        {
            pa_y--;
        } 
        else if (a == 3) 
        {
            pa_x++;
        } 
        else if (a == 4) 
        {
            pa_x--;
        }
        if (b == 1) 
        {
            pb_y++;
        } 
        else if (b == 2) 
        {
            pb_y--;
        } 
        else if (b == 3) 
        {
            pb_x++;
        } 
        else if (b == 4) 
        {
            pb_x--;
        }
        if (pa_x == pb_x && pa_y == pb_y) 
        {
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", pa_x, pa_y, passos);
            return 0;
        }
        if (pa_x < 1 || pa_x > n || pa_y < 1 || pa_y > m) 
        {
            printf("PA saiu na posicao (%d,%d) no passo %d\n", pa_x, pa_y, passos);
            return 0;
        }
        if (pb_x < 1 || pb_x > n || pb_y < 1 || pb_y > m) 
        {
            printf("PB saiu na posicao (%d,%d) no passo %d\n",pb_x, pb_y, passos);
            return 0;
        }
    }
    printf("Nao se encontraram\n");
    return 0;
}

