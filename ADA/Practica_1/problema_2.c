#include <stdio.h>

int main()
{
    int secuencia[3];
    while (1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (scanf("%d", &secuencia[i]) != 1)
                return 0;
        }

        if (secuencia[0] == 0 && secuencia[1] == 0 && secuencia[2] == 0)
        {
            break;
        }

        if (secuencia[0] <= -10000 || secuencia[0] >= 10000 ||
            secuencia[1] <= -10000 || secuencia[1] >= 10000 ||
            secuencia[2] <= -10000 || secuencia[2] >= 10000)
        {
            return -1;
        }

        if (secuencia[2] - secuencia[1] == secuencia[1] - secuencia[0])
        {
            int diferencia = secuencia[1] - secuencia[0];
            int siguiente = secuencia[2] + diferencia;
            printf("AP %d\n", siguiente);
        }
        else if (secuencia[0] != 0 && secuencia[1] != 0)
        {
            int razon = secuencia[1] / secuencia[0];
            int siguiente = secuencia[2] * razon;
            printf("GP %d\n", siguiente);
        }
        else
        {
            return -1;
        }
    }

    return 0;
}