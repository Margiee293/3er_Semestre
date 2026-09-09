def f(x):
    return -3 * (x ** 3) - 8 * (x ** 2) + 6
def punto2(p0,p1):
    p2 = p1 - f(p1) * ( p1 - p0 ) / ( f(p1) - f(p0) )
    return p2
def secante(p0,p1,error_max,iter_max):
    iteracion=1
    while iteracion<=iter_max:
        p2 = punto2(p0,p1)
        error = abs(p2-p1)
        if error <= error_max:
            return p2,iteracion
        p0=p1
        p1=p2
        iteracion+=1
    return p2,iter_max
def main():
    print("--- MÉTODO DE LA SECANTE ---\n")
    p0 = float(input("Ingrese el primer valor inicial (p0): "))
    p1 = float(input("Ingrese el segundo valor inicial (p1): "))
    error_max = float(input("Ingrese el error máximo tolerado: "))
    iter_max = int(input("Ingrese el número máximo de iteraciones: "))
    raiz, iteraciones_realizadas = secante(p0, p1, error_max, iter_max)
    print("\n---RESULTADO---")
    print(f"Raíz aproximada (p2): {raiz:.6f}")
    print(f"Valor de f(p2): {f(raiz):.6e}")
    print(f"Iteraciones realizadas: {iteraciones_realizadas}")
if __name__ == "__main__":
    main()
