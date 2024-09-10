from math import *
from random import *

#PRACTICA 2
#1 Escriba un ciclo definido para imprimir por pantalla todos los números entre 10 y 20
def l1():
     for i in range(10,21):
        print(i)

#2 Escriba un programa que imprima por pantalla todas las fichas del dominó, una por línea y sin repetir
#3 Modifique el programa anterior para que pueda generar fichas de un juego que puede tener números de 0 a n
def domino(n):
    for i in range(n):#i aumentará en 1 por cada n aumentos de j
        for j in range(n):
            print(i,j)

#4 Escriba una función que tome una cantidad m de valores que serán ingresados por el usuario y, a medida que se ingresa cada número, muestre el factorial del mismo. 
# El valor de m es ingresado inicialmente por el usuario.

def fact(i):#función auxiliar que calculará el factorial de un número i
    if i== 0 or i== 1:
        return 1
    else: 
        return i*fact(i-1)

def factorial(m):
    for i in range(m):
        f= int(input("Ingrese el numero que desea ver su factorial: "))
        print(fact(f))
    
#5 Escriba una función para convertir una temperatura de Fahrenheit a Celsius, genere una tabla de conversión de temperaturas, desde 0◦F hasta 120◦F, de 10 en 10.

def grados():
    for i in range(0,120,10):
        print((i-32)*(5/9))


#6 Escriba una función que reciba un número n como parámetro e imprima los primeros n números triangulares, junto con sus respectivos índices.
def triangular(n):#función auxiliar que calcula el triangular de un número n
    if n == 0:
        return 0
    else:
        return n + triangular(n-1)

def triangular_indices(m):
    
    for i in range(1,m+1):
        print(f"{i} - {triangular(i)}")

#7 Escriba una función que le pida al usuario que ingrese un número positivo. Si el usuario ingresa cualquier cosa que no sea lo pedido se le debe informar de su error mediante
#un mensaje y volver a pedirle el número, repitiendo este proceso hasta que ingrese lo pedido.
def pos():
    x  = int(input("Ingrese un numero positivo: "))
    while x < 0:
        print("El numero ingresado es negativo")
        x  = int(input("Ingrese un numero positivo: "))

#8 Escriba un programa que permita al usuario ingresar un conjunto de notas, preguntando a cada paso si desea ingresar más notas, e imprima el promedio correspondiente al finalizar la toma de datos
def notas(n=0,m=0,x= "si"):
    while x == "si":
        y = int(input("Ingrese la nota recibida: "))
        x = str(input("Desea seguir ingresando mas notas?: "))
        x = x.lower()
        n +=y
        m +=1
    print(n/m)

#9 Escriba un programa que pida dos números enteros. El programa pedirá de nuevo el segundo número mientras no sea mayor que el primero. 
#El programa terminará escribiendo los dos números.

def mayor():
    x = int(input("Ingrese el primer número: "))
    y = int(input("Ingrese el segundo número: "))
    while x > y:
        y= int(input("Ingrese el segundo número: "))
    print(x,y)    
    
#10 Escriba una función que reciba dos números como parámetros y devuelva cuántos múltiplos del primero hay que sean menores que el segundo.
def multiplos(m=0):#función multiplos mediante bucle for
    x = int(input("Ingrese el primer num: "))
    y = int(input("Ingrese el segundo num: "))
    for i in range(0,y,x):
        if i < y:
            m = m+1
    print(m)

def multiplos2(m=0):#función multiplos mediante bucle while
    x = int(input("Ingrese el primer número: "))
    y = int(input("Ingrese el segundo número: "))
    while x*m < y:
        m = m+1
    print(m)

#11 Escriba un programa que contenga una contraseña inventada. 
#El programa debe preguntarle al usuario la contraseña y no permitirle continuar hasta que la haya ingresado correctamente, con una cantidad de intentos límites fija.
def contraseña(c= "Hola mundo!", i= 3):
    s= input("Ingrese su contraseña: ")
    while s != c and i != 1:
        print(False)
        i = i-1
        s= input("Ingrese su contraseña: ")
    if s==c:    
        print(True)

#12 2. Escriba una función que reciba un número natural e imprima todos los números primos que hay menores o iguales que ese número.
def esprimo(n):#funación auxiliar que determina si el número ingresado es primo o no
    for i in range(2,n):
        if n%i == 0:
            return False
        else:
            return True

def todosprimos():
    n = int(input("ingrese un número para visualizar sus anteriores primos: "))
    for i in range(n+1):
        if esprimo(i):
            print(i)

#13 Escriba una función es_potencia_de_dos que reciba como parámetro un número natural y devuelva True si el número es una potencia de 2 y False en caso contrario
def pot2(x, i=0):
    if type(x)== int and x > 0:
        while (2**i <= x):
            if 2**i == x:
                return True
            i = i+1
        return False

#Escriba una función que, dados dos números naturales pasados como parámetros, devuelva la suma de todas las potencias de 2 que hay en el rango formado por esos números
def sumpot(z=0):
    x= int(input("Ingrese el primer número como parámetro:"))
    y= int(input("Ingrese el segundo número como parámetro"))
    for i in range(x,y+1):
        if pot2(i):
            z= z+i
    print(z)        

#14 Simule lanzamientos de un dado. Muestre el resultado en cada intento y finalice cuando salga el número 6. También añada cuantas veces se lanzó el dado.
def dado(l=1):
    a = randint(1,6)
    while a != 6:
        print(a)
        a =randint(1,6)
        l+= 1
    print(a)
    print(f"el dado se lanzo: {l} veces")

#15 Simule n lanzamientos de dos dados, donde n es un valor que se debe pedir que se ingrese por teclado. Muestre cuántas veces los dados tuvieron el mismo resultado.
def dados(x=0):
    l= int(input("Ing lanzmientos: "))
    for i in range(l+1):
        A = randint(1,6)
        B = randint(1,6)
        if A == B :#caso en que dado A sea igual a dado B
         x+=1
    print(x)    

#16 Simule n lanzamientos de un dado en un juego con las siguientes reglas:
#si sale 6 gana 4 dolares; si sale 3 gana 2 dolares; si sale 1 sigue jugando y si sale 2, 4 o 5 pierde 2 dolares.
#Muestre los valores que salen y el resultado final del juego
def juego(m=0):
    l= int(input("Ing lanzmientos: "))
    for i in range(l+1):
        a = randint(1,6)
        if a== 6:
            m+=4
        elif a== 3:
            m+= 2
        else:
            m-=2
    print(m)

