#include <stdio.h>

int main()
{
    int n = 0, m = 0, count = 0;

    printf("-----PROBLEMA 4-----\n");
    printf("DIFFERENT DIGITS\n");
    printf("Ingrese el valor de N: ");
    scanf("%d", &n);
    printf("Ingrese el valor de M: ");
    scanf("%d", &m);

    if (n < 1 || n > m || m > 5000)
    {
        return -1;
    }

    for (int i = n; i <= m; i++)
    {
        int usado[10] = {0};
        int repetido = 0;
        int temp = i;

        do
        {
            int d = temp % 10;
            if (usado[d] == 1)
            {
                repetido = 1;
                break;
            }
            usado[d] = 1;
            temp = temp / 10;
        } while (temp != 0);

        if (repetido == 0)
        {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}