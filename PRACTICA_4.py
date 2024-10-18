#PRACTICA_4
from random import *
#1 Escriba una función que, dados una lista desordenada y un elemento y devuelva: 1) la cantidad de apariciones del elemento. 2) su primer posición en la lista. 3) una lista con sus posiciones
def apariciones(l,e):
    x=0
    for j in l:
        if j == e:
            x+=1

    pos=l.index(e)
    list1=[]
    for i in range(len(l)):
        if l[i]==e:
            list1.append(i)

    return x,pos,list1
 
#2 . Escriba una función que tome una lista de números desordenada y devuelva: su valor maximo y una tupla con este valor y su posición
def maximo(l):
    x=l[0]
    for e in l:
        if e > x:
            x=e
    y= (x,l.index(x))        
    return x,y

#3 Escriba una función que tome una lista ordenada y un elemento. Si el elemento se encuentra en la lista, debe encontrar su posición mediante búsqueda binaria y devolverlo. Si
#no se encuentra, debe agregarlo a la lista en la posición correcta y devolver esa nueva posición
def busqueda(l,e):
    inicio=0
    fin=len(l)-1
    while inicio<=fin and l[(inicio+fin) // 2]!=e:
        medio=(inicio+fin) // 2
        if l[medio] < e:
            inicio=medio+1
        elif l[medio]> e:
            fin=medio-1

    if l[medio]==e:
        return medio
    elif medio==0:
        l.insert(0,e)
        return 0,l
    elif e > l[-1]:
        l.insert(len(l),e)
        return medio,l
    else: 
        l.insert(medio,e)
        return medio,l

#4 . Escriba una función que reciba una lista de tuplas y devuelva un diccionario en donde las claves sean los primeros elementos de las tuplas y los valores una lista con los segundos
def diccionario(l):
    d={}
    for elemento in l:
        if elemento[0] not in d: 
            d[elemento[0]]=[elemento[1]]
        else: 
            d[elemento[0]]=d[elemento[0]]+[elemento[1]]
    return d

#5 A) Escriba una función que reciba una cadena y devuelva un diccionario con la cantidad de apariciones de cada palabra en la cadena
def apariciondic(s):
    a={}
    s= s.split(" ")
    
    for e in s:
        if e in a:
            a[e] = a[e] + 1
        else:
            a[e]= 1
    
    return a
#B) Escriba una función que reciba una cadena de texto y devuelva la cantidad de apariciones de cada caracter en un diccionario
def apariciondic2(s):
    a={}
    for e in s:
        if e in a:
            a[e] = a[e] + 1
        else:
            a[e]= 1
    
    return a
#C) Escriba una función que reciba una cantidad de iteraciones de una tirada de 2 dados a realizar y devuelva un diccionario en el cual las claves sean los resultados de la suma de
#los dados y los valores sean la cantidad de veces que se observa cada resultado.
def dados(n):
    d={}
    for i in range(n):
        a= randint(1,6)
        b= randint(1,6)
        if a+b not in d:
            d[a+b]=1
        else:
            d[a+b]= d[a+b]+1
    return d

#6 Escriba una función que reciba un texto y devuelva un diccionario que, para cada caracter presente en el texto, almacene la cadena más larga en la que se encuentra ese caracter. 
def palabralarga(s):
    d={}
    s=s.split()
    for elemento in s:
        for caracter in elemento:
            if caracter not in d:
                d[caracter] = elemento
            elif caracter in d and len(elemento)> len(d[caracter]):
                d[caracter]= elemento
    return d

#7 Escriba una función que reciba como entrada un diccionario cuyas claves sean los nombres de los estudiantes y cuyos valores sean las listas de sus calificaciones y devuelva:
#A) dado el nombre de un estudiante, devuelva el promedio de sus calificaciones.
def notas(a,s):
    x = 0
    for i in (a[s]):
        x+=i
    x= x/len(a[s])
    
    return x
#B) devuelva el nombre del estudiante con el mayor promedio.    
def mayorpromedio(a):
    mayorp= 0
    estm=""
    for e in a:
        prom=notas(a,e)
        if prom > mayorp:
            mayorp=prom
            estm= e     
        
    return estm

#8 Escriba una función que tome una cadena de texto y un diccionario cuyas claves sean palabras y cuyos valores sean listas de sinónimos de dichas palabras. La función debe
#reemplazar cada palabra de la cadena recibida por un sinónimo elegido de forma aleatoria. Si una palabra no tiene sinónimos, debe dejar la original.
def sinonimos(s,d):
    s=s.split()
    ns=""
    for e in d:
        if d[e]==[]:
            ns=ns+" "+e
        else:
            ns=ns+" "+d[e][randint(0,len(d[e])-1)]
    return ns

#9 Escriba una función que tome como entrada dos diccionarios. Ambos tienen como clave nombres de productos. Los valores del primero son los precios de cada producto,
#mientras que los valores del segundo son las cantidades de cada producto que hay en el carrito. La función debe devolver el monto total de la compra realizada.
def carrito(d1,d2):
    monto=0
    for e in d1:
        monto= monto +(d1[e]*d2[e])
    return monto

#CONJUNTOS

#10 Escriba una función que tome una lista y utilice un conjunto para eliminar sus elementos duplicados
def elimina_duplicados(l):
   return set(l)

#11 Escriba una función que tome dos cadenas de texto y devuelva un conjunto con las palabras que aparecen en ambas cadenas (sin tener en cuenta mayúsculas y minúsculas).
def palabras(s,g):
   s= s.lower()
   g= g.lower()
   return set(s.split())& set(g.split())

#12 Escriba una función que, dados dos conjuntos, devuelva un nuevo conjunto que contenga los elementos que están en uno de los conjuntos pero no en ambos.
def difsim(s,g):
    return (s|g)-(s&g)

#13 Escriba una función que tome una lista desordenada de números naturales como entrada, calcule cuál es el número N máximo de la lista y devuelva un conjunto con los
#números naturales menores a N que no están en la lista.
def menores(l):
    l.sort()
    n=l[-1]
    menores=set(range(1,n))
    x=menores-set(l)
    return x

#14 Escriba una función que tome como entrada un diccionario cuyas claves sean los nombres de las personas asistentes a la reunión y cuyos valores sean las listas de los días disponibles
#que tiene cada persona. La función debe devolver un conjunto con los días en los que todas las personas pueden asistir.
def inter(dic):
    a=set(range(1,31))
    for e in dic:
        b=set(dic[e])
        a=a.intersection(b)
    return a

