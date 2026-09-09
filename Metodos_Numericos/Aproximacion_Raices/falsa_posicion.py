def f(x):
    return x ** 3 - 2
def punto2(p0,p1):
    p2 = p1 - f(p1)*(p1-p0)/(f(p1)-f(p0))
    return p2
def falsa_posicion(a,b,error_max,iter_max):
    iteracion=1
    p_anterior = a
    while iteracion <= iter_max:
        p2 = punto2(a,b)
        error = abs(p2-p_anterior)
        if error <= error_max:
            return p2, iteracion
        if f(a)*f(p2)<0:
            b=p2
        else:
            a=p2
        p_anterior = p2
        iteracion+=1
    return p2, iter_max
def main():
    print("--- MÉTODO DE FALSA POSICIÓN ---")
    a = float(input("Ingrese el extremo inferior (a): "))
    b = float(input("Ingrese el extremo superior (b): "))
    error_max = float(input("Ingrese el error máximo tolerado: "))
    iter_max = int(input("Ingrese el número máximo de iteraciones: "))
    raiz, iteraciones_totales = falsa_posicion(a,b,error_max,iter_max)
    print(f"La raíz aproximada es: {raiz}")
    print(f"Valor de f(raíz): {f(raiz)}")
    print(f"Iteraciones realizadas: {iteraciones_totales}")
if __name__ == "__main__":
    main()
