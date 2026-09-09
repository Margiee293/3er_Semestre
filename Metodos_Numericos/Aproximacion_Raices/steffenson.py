def f(x):
    return (3 + x -2(x^2))
def steffenson (p0,p1,p2):
    return (p0-((p1-p0)^2)/(p2-2*p1+p0))
def metodo_steffenson(p0,p1,p2,error_max,iter_max):
    iteracion=1
    p_anterior = p0
    while iteracion <= iter_max:
        p2 = steffenson(p0,p1,p2)
        error = abs(p2-p_anterior)
        if error <= error_max:
            return p2, iteracion
        p0 = p1
        p1 = p2
        p_anterior = p2
        iteracion+=1
    return p2, iter_max
def main():
    print("--- MÉTODO DE STEFFENSON ---")
    p0 = float(input("Ingrese el primer valor inicial (p0): "))
    p1 = float(input("Ingrese el segundo valor inicial (p1): "))
    p2 = float(input("Ingrese el tercer valor inicial (p2): "))
    error_max = float(input("Ingrese el error máximo tolerado: "))
    iter_max = int(input("Ingrese el número máximo de iteraciones: "))
    raiz, iteraciones_totales = metodo_steffenson(p0,p1,p2,error_max,iter_max)
    print(f"La raíz aproximada es: {raiz}")
    print(f"Valor de f(raíz): {f(raiz)}")
    print(f"Iteraciones realizadas: {iteraciones_totales}")
if __name__== "__main__":
    main()
