def f(x):
    return x ** 3 - 2

def df(x):
    return 3 * (x ** 2)

def newton_raphson(p0, error_max, max_iter):
    iteracion = 1

    while iteracion <= max_iter:
        p = p0 - (f(p0) / df(p0))
        error = abs (p - p0)
        if error <= error_max:
            return p, iteracion
        p0 = p
        iteracion += 1

    return p, max_iter
def main():
    print("--- MÉTODO DE NEWTON-RAPHSON ---")
    p0= float(input("Ingrese el valor inicial (p0): "))
    error_max = float(input("Ingrese el error máximo tolerado: "))
    max_iter = int(input("Ingrese el número máximo de iteraciones: "))

    raiz, interaciones_totales = newton_raphson(p0, error_max, max_iter)

    print("\n--- RESULTADO ---")
    print(f"Raíz aproximada (p): {raiz:.6f}")
    print(f"Valor de f(p): {f(raiz):.6e}")
    print(f"Iteraciones realizadas: {interaciones_totales}")    
if __name__ == "__main__":
    main()