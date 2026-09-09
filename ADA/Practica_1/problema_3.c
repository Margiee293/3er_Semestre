#include <stdio.h>

int main()
{
    int n_palos = 0;

    printf("-----PROBLEMA 3-----\n");
    printf("STICKS\n");
    printf("Ingrese la cantidad de palos a utilizar: ");
    scanf("%d", &n_palos);

    if (n_palos < 4)
    {
        printf("No se puede formar un rectangulo con menos de 4 palos.\n");
        return 0;
    }

    int long_palo[n_palos];

    printf("Ingrese las longitudes de los palos separadas por un espacio: ");
    for (int i = 0; i < n_palos; i++)
    {
        scanf("%d", &long_palo[i]);
    }

    for (int j = 1; j < n_palos; j++)
    {
        int key = long_palo[j];
        int i = j - 1;
        while (i >= 0 && long_palo[i] < key)
        {
            long_palo[i + 1] = long_palo[i];
            i--;
        }
        long_palo[i + 1] = key;
    }

    int lado1 = 0, lado2 = 0;

    for (int i = 0; i < n_palos - 1; i++)
    {
        if (long_palo[i] == long_palo[i + 1])
        {
            if (lado1 == 0)
            {
                lado1 = long_palo[i];
                i++;
            }
            else if (lado2 == 0)
            {
                lado2 = long_palo[i];
                i++;
                break;
            }
        }
    }

    if (lado1 > 0 && lado2 > 0)
    {
        int area = lado1 * lado2;
        printf("%d\n", area);
    }
    else
    {
        printf("-1.\n");
    }

    return 0;
}