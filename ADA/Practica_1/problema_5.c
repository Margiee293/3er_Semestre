#include <stdio.h>
#define NUM_PRIMOS 15000
int primos[NUM_PRIMOS];
void primo(int n)
{
    int ultimo_primo = 2;
    for (int i = 0; i < n; i++) // para el arreglo
    {
        for (int j = ultimo_primo;; j++) // para los numeros
        {
            int div = 2, primo = 0;
            do // validacion de primo o no
            {
                if (j % div == 0)
                    primo += 1;
                div += 1;
            } while (j >= div);
            if (primo > 1)
                continue; // pasa al sig numero
            else if (primo == 1 && div > j)
            {
                primos[i] = j;
                ultimo_primo = j + 1;
                break;
            }
        }
    }
}
int main()
{
    int n = 0, max_primos = 0;
    printf("-----PROBLEMA 5-----\n");
    printf("CRIPTOGRAPHY\n");
    printf("Ingrese el número de consultas, y los enteros: ");
    scanf("%d", &n);
    if (n > NUM_PRIMOS)
        return -1;
    int num_usuario[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num_usuario[i]);
        if (num_usuario[i] > NUM_PRIMOS)
            return -1;
        if (num_usuario[i] > max_primos)
            max_primos = num_usuario[i]; // hasta que numero generar primos
    }
    primo(max_primos);
    printf("\nResultados:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", primos[num_usuario[i] - 1]); // el -1 es porque el array cuenta desde 0
    }

    return 0;
}