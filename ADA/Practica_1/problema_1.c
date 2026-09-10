#include <stdio.h>

int main()
{
    int n_estudiantes = 0, count = 0, final = 0;
    printf("-----PROBLEMA 1-----\n");
    printf("ANGRY STUDENTS\n");
    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &n_estudiantes);
    if (n_estudiantes <= 0 || n_estudiantes > 100)
    {
        printf("Cantidad de estudiantes inválida.\n");
        return -1;
    }
    printf("Ingrese el estado de los estudiantes sin espacios (A para enojado, P para paciente): ");
    char estudiantes[n_estudiantes + 1];
    scanf("%s", estudiantes);

    do
    {
        final = 1;
        for (int i = n_estudiantes - 2; i >= 0; i--)
        {
            if (estudiantes[i] == 'A' && estudiantes[i + 1] == 'P')
            {
                estudiantes[i + 1] = 'A';
                final = 0;
            }
        }
        if (final == 0)
        {
            count++;
        }
    } while (final == 0);

    printf("%d\n", count);
    return 0;
}