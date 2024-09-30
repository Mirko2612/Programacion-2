#PRACTICA 3

#1 Escriba una función posicionesMultiplo que tome una lista y un número y retorne la lista formada por los elementos que están en las posiciones múltiplos de ese número.
def posiciones_multiplo(l,n,x=[],posicion=0):
 if l == []:
  return x
 
 elif posicion % n == 0:
  x.append(l[0])
  return posiciones_multiplo(l[1:],n,x,posicion+1)
  
 else:
  return posiciones_multiplo(l[1:],n,x,posicion+1)

#2 Escriba una función que tome una lista de números y devuelva la suma acumulada
def suma_acumulada(l,x = []):
 if len(l) == 0:
  return x
 
 elif x==[]:
    x.append(l[0])
    return suma_acumulada(l[1:],x)
 
 else:
  x.append(x[-1] + l[0]) 
  return suma_acumulada(l[1:],x)

#3 Escriba una función llamada elimina que tome una lista y elimine el primer y último elemento de la lista. La función debe devolver una nueva lista con los elementos
# que no fueron eliminados
def elimina_elementos(l):
 print(l[1:l[-2]])

#4 Escriba una función ordenada que tome una lista como parámetro y devuelva True si la lista está ordenada en orden ascendente y False en caso contrario
def ordenada(l,x = True):
 if len(l) == 1:
  return x
 
 elif l[1] > l[0]:
  return ordenada(l[1:],x)
 
 else:
  return False
 
#5 . Escriba una función llamada duplicado que tome una lista y devuelva True si tiene algún elemento duplicado. La función no debe modificar la lista
lista3=[1,2,3,4,5,1]
def duplicado(l):
 if len(l) == 1:
  return False  
 elif sorted(l)[1] == sorted(l)[0]:
  return True
 else:
  return duplicado(l[1:])

#6 Escriba una función llamada eliminaDuplicados que tome una lista y devuelva una nueva lista con los elementos únicos de la lista original
def eliminaduplicados(l,i=0):
  list.sort(l)
  if i+1 == len(l):
   return l
  elif l[i]==l[i+1]:
    return eliminaduplicados(l[:i]+(l[i+1:]),i) 
  else:
   return eliminaduplicados(l,i+1)
 
#7 Escriba una función que tome una lista y retorne la cantidad de elementos distintos que tiene. Se recomienda usar la función del ejercicio anterior.
def cant_distintos(l):
 return len(eliminaduplicados(l))

#8 Implemente la función busquedaDicotomica que toma una lista de palabras ordenadas alfabéticamente y una palabra a buscar y retorna si la palabra está en la lista o no.
def busquedadico(l,g):
    inicio=0
    fin=len(l)-1
    while inicio<=fin and l[(inicio+fin) // 2]!=g:
        medio=(inicio+fin) // 2
        if l[medio] < g:
            inicio=medio+1
        elif l[medio]> g:
            fin=medio-1

#9 Escriba un programa que tenga una función que tome una cadena y muestre cada caracter que la forma del último al inicial.
def darvuelta(s,i=-1):
 if -i == len(s):
  return print(s[i])
 else:
  print(s[i])
  return darvuelta(s,i-1)
 
#10 Escriba un programa que contenga a la función contar(l, x) que cuente cuántas veces aparece un carácter l dado en una cadena x.
def conta(l,x,i=0,c=0):
 if len(x) == c:
  return i
 elif l == x[c]:
  return conta(l,x,i+1,c+1)
 else:
  return conta(l,x,i,c+1)

#11 Escriba un programa que cuente cúantas veces aparecen cada una de las vocales en una cadena. No importa si la vocal aparece en mayúscula o en minúscula.
def vocales(s,a=0,e=0,i=0,o=0,u=0,c=0):
 s.lower()
 if c == len(s):
  return print("aparecen "+str(a)+" a \n" 
                "aparecen "+str(e)+" e \n"
                "aparecen "+str(i)+" i \n" 
                "aparecen "+str(o)+" o \n"
                "aparecen "+str(u)+" u ")
 elif s[c] == "a":
  return vocales(s,a+1,e,i,o,u,c+1)
 elif s[c] == "e":
  return vocales(s,a,e+1,i,o,u,c+1)
 elif s[c] == "i":
  return vocales(s,a,e,i+1,o,u,c+1)
 elif s[c] == "o":
  return vocales(s,a,e,i,o+1,u,c+1)
 elif s[c] == "u":
  return vocales(s,a,e,i,o,u+1,c+1)
 else:
  return vocales(s,a,e,i,o,u,c+1)

#12 Escriba un programa que contenga una función que reciba como parámetro una cadena de palabras separadas por espacios y devuelva como resultado cuántas palabras de
# más de cinco letras tiene la cadena dada.

def palabra5(s,i=0,j=0):
 if j == (len(s.split(" "))):
  return i
 elif len(s.split(" ")[j]) >= 5:
  return palabra5(s,i+1,j+1)
 else: 
  return palabra5(s,i,j+1)

#13 Escriba una función llamada poker que reciba cinco cartas de la baraja francesa e informe (devuelva el valor lógico correspondiente) si esas cartas forman o no un póker 
def poker(x1,c=0):
  for i in range(5):
    if x1[0][1]== x1[i][1]:
     c+=1 
  if c>=4:
    print(True)
  else: 
   c=0
  for i in range(5):
    if x1[1][1]== x1[i][1]:
      c+=1 
  if c>=4:
    print(True)
  else:
     print(False)

#14 Escriba una función sumaTiempo que reciba dos tiempos dados y devuelva su suma.
def sumatiempo(t1,t2):
 st= (t1[0]+t2[0],t1[1]+t2[1],t1[2]+t2[2])
 
 if t1[2]+t2[2]>=60:
  st=(st[0],st[1]+1,st[2]-60)
 
 elif t1[1]+t2[1]>=60:
  st=(st[0]+1,st[1]-60,st[2])

 return st

#15 Escriba una función diaSiguienteE que, dada una fecha expresada como la tupla (Día, Mes, Año)calcule el día siguiente al dado en el mismo formato 
def diasiguienteE(t):
 t1=(t[0]+1,t[1],t[2])
 if  t1[0] > 31 and (t[1] in [1,3,5,7,8,10]):
  t1=(t[0]-30,t[1]+1,t[2])
 elif t1[0] > 30 and (t[1] in [4,6,9,11]):
  t1=(t[0]-29,t[1]+1,t[2])
 elif t1[0] > 29 and t[1]==2:
  t1=(t[0]-28,t[1]+1,t[2])
 elif t1[0] > 31 and t[1]==12:
  t1=(t[0]-30,t[1]-11,t[2]+1)
 return t1

#16 Escriba una función diaSiguienteT que, dada una fecha expresada como la tupla (Día, Mes, Año) (donde Día y Año son números enteros, y Mes es el texto "Ene", "Feb",
# ..., "Dic", según corresponda), calcule el día siguiente al dado en el mismo formato.
def diasiguienteT(t):
 m=("Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic")
 n=m.index(t[1])
 t1=(t[0]+1,t[1],t[2])
 if  t1[0] > 31 and (t[1] in ["Ene","Mar","May","Jul","Ago","Oct"]):
  t1=(t[0]-30,m[n+1],t[2])
 elif t1[0] > 30 and (t[1] in ["Abr","Jun","Sep","Nov"]):
  t1=(t[0]-29,m[n+1],t[2])
 elif t1[0] > 29 and t[1]=="Feb":
  t1=(t[0]-28,"Mar",t[2])
 elif t1[0] > 31 and t[1]=="Dic":
  t1=(t[0]-30,"Ene",t[2]+1)
 return t1

#17 Escriba una función que tome dos fichas de dominó e indique si encajan o no. Las fichas son recibidas en dos tuplas
def encajan(t1,t2):
 if t1[0]==t2[0] or t1[1]==t2[1] or t1[0]==t2[1] or t1[1]==t2[0]:
  return True
 else:
  return False
 
#18 Escriba una función que tome dos fichas de dominó e indique si encajan o no. Las fichas son recibidas en una cadena,
def domino(s):
 s= s[1:-1]
 s= s.split()
 s= s[0].split("-") + s[1].split("-")
 a = (s[0],s[1])
 b = (s[2],s[3])
 return encajan(a,b)





