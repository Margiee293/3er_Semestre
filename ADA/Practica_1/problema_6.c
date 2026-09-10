#include <stdio.h>

int main()
{
    int f = 0, c = 0;

    while (1)
    {
        printf("-----PROBLEMA 6-----\n");
        printf("PUNTOS DE SILLA DE UNA MATRIZ\n");
        printf("Ingrese el número de filas y columnas separado por un espacio: ");
        scanf("%d %d", &f, &c);

        if (f == 0 && c == 0)
        {
            break;
        }

        int matriz[300][300];

        printf("\nIngrese los valores de la matriz separados por un espacio:\n");
        for (int i = 0; i < f; i++)
        {
            for (int j = 0; j < c; j++)
            {
                scanf("%d", &matriz[i][j]);
            }
        }

        int punto_silla = 0; // 0=falso y 1=verdadero

        for (int i = 0; i < f; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int val = matriz[i][j];

                int min_f = 1, max_f = 1, min_c = 1, max_c = 1;

                for (int k = 0; k < c; k++)
                {
                    if (matriz[i][k] < val)
                        min_f = 0;
                    if (matriz[i][k] > val)
                        max_f = 0;
                }

                for (int k = 0; k < f; k++)
                {
                    if (matriz[k][j] < val)
                        min_c = 0;
                    if (matriz[k][j] > val)
                        max_c = 0;
                }

                if ((min_f == 1 && max_c == 1) || (max_f == 1 && min_c == 1))
                {
                    punto_silla = 1;
                    break;
                }
            }

            if (punto_silla == 1)
            {
                break;
            }
        }

        if (punto_silla == 1)
        {
            printf("SI\n\n");
        }
        else
        {
            printf("NO\n\n");
        }
    }

    return 0;
}