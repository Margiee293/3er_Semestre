def f(x):
    """Función a evaluar: f(x) = -3x^3 - 8x^2 + 6"""
    return -3 * (x ** 3) - 8 * (x ** 2) + 6

def biseccion(a, b, erro_max, max_iter):
    """Calcula la raíz de f(x) mediante el Método de Bisección."""
    fa = f(a)
    fb = f(b)

    if fa * fb <= 0:
        return None, "Error: f(a) y f(b) deben tener signos opuestos."

    iteracion = 1

    while iteracion <= max_iter:
        c = (a + b) / 2
        fc = f(c)
        error = abs(b - a) / 2

        # Criterio de parada por tolerancia o raíz exacta
        if error <= erro_max or fc == 0:
            return c, iteracion

        # Actualización del intervalo
        if fa * fc < 0:
            b = c
            fb = fc
        else:
            a = c
            fa = fc

        iteracion += 1

    return c, max_iter  

def main():
    print("--- MÉTODO DE BISECCIÓN ---\n")
    
    a = float(input("Ingrese el extremo inferior (a): "))
    b = float(input("Ingrese el extremo superior (b): "))
    erro_max = float(input("Ingrese el error máximo tolerado: "))
    max_iter = int(input("Ingrese el número máximo de iteraciones: "))

    raiz, iteraciones_realizadas = biseccion(a, b, erro_max, max_iter)

    if raiz is None:
        print(f"\n{iteraciones_realizadas}")  # Muestra el mensaje de error
    else:
        print("\n--- RESULTADO ---")
        print(f"Raíz aproximada (c): {raiz:.6f}")
        print(f"Valor de f(c): {f(raiz):.6e}")
        print(f"Iteraciones realizadas: {iteraciones_realizadas}")

if __name__ == "__main__":
    main()