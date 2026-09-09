import math

def f(x):
    return (((2 * x * (2 + math.sin(6 * x - 2)) ** 2) / math.exp(2 * x + 6) + 5 * x) / 3) ** (1 / 3)

def punto_fijo(x0, error_max, iter_max):
    iteracion = 1
    p_anterior = x0
    while iteracion <= iter_max:
        xi = f(p_anterior)
        error =abs(xi - p_anterior)
        if error <= error_max:
            return xi, iteracion
        p_anterior =xi
        iteracion += 1
    return xi, iter_max
def main():
    x0 = float(input("Ingrese el valor inicial: "))
    error_max = float(input("Ingrese el error máximo permitido: "))
    iter_max = int(input("Ingrese el número máximo de iteraciones: "))

    raiz, iteraciones = punto_fijo(x0, error_max, iter_max)

    print(f"La raíz aproximada es: {raiz}")
    print(f"Número de iteraciones realizadas: {iteraciones}")
if __name__ == "__main__":
    main()