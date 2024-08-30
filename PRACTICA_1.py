#!/usr/bin/python

#practica 1

#1 y 2 Escriba un programa que imprima los primeros 25 números naturales pares y 100 números naturales pares

def numeros_pares(x):
    if x== 0:
        print(x)
    elif x % 2 == 0:
        print(x)
        numeros_pares(x-1)
    
    else:
        numeros_pares(x-1)
    return x


#3 Escriba un programa que imprima los primeros n números pares mayores que m.
def numeros_pares2(n,m):
    if m % 2 == 0 :
        mostrar_p(n,m+2)
    else: 
        mostrar_p(n,m+1)
    
    
#auxiliar: si n llega a uno, termina mostrando el numero m sino, mostrará m y llamará a la funcion numeros_pares2 
def mostrar_p(n,m):
    if n== 1:
        print(m)
    else:
        print(m)
        numeros_pares2(n-1,m)
    
    return n,m


#4  Escriba un programa que calcule e imprima el resultado de la suma de los primeros 50 números naturales usando una función recursiva
def suma_50(x = 50):
    if x == 0:
        return 0
    else:
        resultado = x + suma_50(x - 1)
        
        if x == 50:
            print(resultado)
        return resultado
    
#5  Escriba un programa que calcule e imprima el resultado de la suma de los primeros n números naturales usando una función recursiva

def suma_n(x,resultado= 0):

    if x == 0:
        print(resultado)
        return resultado
    else:
        return suma_n(x - 1,resultado + x)
        
#6 Escriba un programa que calcule e imprima el resultado de la suma de los números naturales mayores que n y menores que m usando una función recursiva

def suma_nm(n,m):
    #ejemplo_ suma_n,m(2,6)= 2+3+4+5+6 = 20
    if n == m:
        return m
    else:
        return n + suma_nm(n+1,m)


#7) Escriba un programa que reciba un nombre y retorne el nombre pasado concatenado 2 veces.

def duplica(s):
    return s * 2

#print(duplica("hola"))

#8) Escriba un programa que reciba un nombre y un número n, y retorne el nombre pasado concatenado n veces.

def duplica2(s,n):
    return s * n

#9) 
# a) Escriba una función suma que reciba dos números y retorne el resultado de la suma deambos.

def suma(x,y):
    return x+y

# b) Escriba una función resta que reciba dos números y retorne el resultado de la resta deambos.

def resta(x,y):
    return x-y

# c) Escriba una función multiplica que reciba dos números y retorne el resultado de la multiplicación de ambos números.

def multiplica(x,y):
    return x*y

# d) Escriba una función divide que reciba dos números y retorne el resultado de la división de ambos números.

def divide(x,y):
    return x/y

# e) Escriba un programa que simule una calculadora con las funciones escritas anteriormente
# la funcion se llamará automaticamente luego de realizar una operación hasta que se presione el numero 5
def menu():
    print("\n1.Suma \n2.Resta\n3.Multiplica\n4.Divide\n5.Salir")
    opcion = int(input("Elija la operacion que desea realizar: "))
    if opcion == 1:
         num1 = (int (input ("Escriba el primer numero que desea sumar: ")))
         num2 = (int (input ("Escriba el segundo numero que desea sumar: ")))
         print(suma(num1,num2))
         menu()

    elif opcion == 2:
         num1 = (int (input ("Escriba el primer numero que desea restar: ")))
         num2 = (int (input ("Escriba el segundo numero que desea restar: ")))
         print(resta(num1,num2))
         menu()
    elif opcion == 3:
         num1 = (int (input ("Escriba el primer numero que desea multiplicar: ")))
         num2 = (int (input ("Escriba el segundo numero que desea multiplicar: ")))
         print(multiplica(num1,num2))
         menu()
    elif opcion == 4:
         num1 = (int (input ("Escriba el primer numero que desea dividir: ")))
         num2 = (int (input ("Escriba el segundo numero que desea dividir: ")))
         print(divide(num1,num2))
         menu()
    elif opcion == 5:
        None
    else:
        print("Ingrese un numero valido.")
        menu()

