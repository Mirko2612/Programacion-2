import random
def leer_archivo(nombre_archivo):#Leer archivo toma el nombre del archivo de entrada y crea un diccionario donde la clave sera el nombre del producto y su valor es precio o cantidad
    try:
        archivo=open(nombre_archivo,"r")
    except FileNotFoundError:
        print("Error,el archivo, no existe")
        exit()
    articulos={}
    for linea in archivo:
        nombre_articulo,precio_cantidad=linea.strip().split(",")
        articulos[nombre_articulo]=int(precio_cantidad)
    archivo.close()
    return articulos

def leer_promociones(nombre_archivo):#Leer promociones toma el nombre del archivo de promociones y crea una lista de tuplas que son las promociones
    try:
        archivo=open(nombre_archivo,"r")
    except FileNotFoundError:
        print("Error,el archivo, no existe")
        exit()
    promociones=[]
    for linea in archivo:
        articulo1,cant1,articulo2,cant2,precio_promo=linea.strip().split(",")
        promociones.append((articulo1,int(cant1),articulo2,int(cant2),int(precio_promo)))#Agrega a la lista la tupla de la promocion
    archivo.close()
    return promociones

def aplicar_promocion(lista_promociones,carrito,diccionario_articulos):#aplicar_promocion toma la lista de promociones, el diccionario "carrito" y el diccionario de los articulos y crea 2 listas de strings y un precion final
    productos_sueltos=[]
    precio_final=0
    productos_promocion=[]
    while lista_promociones:#Mientras mi lista de promociones sea no vacia
        indice_random=random.randint(0,len(lista_promociones)-1)
        promocion= lista_promociones[indice_random]
        articulo1,cant1,articulo2,cant2,precio_promo=promocion[0],promocion[1],promocion[2],promocion[3],promocion[4]
        while carrito.get(articulo1, 0) >= cant1 and carrito.get(articulo2, 0) >= cant2: #Mientras cumpla el requisito de la promocion:
            productos_promocion.append(f"{articulo1}, {cant1} - {articulo2}, {cant2} - {precio_promo}")#Agrega a la lista de productos con promocion aplicada, el string con la informacion
            carrito[articulo1] -= cant1
            carrito[articulo2] -= cant2
            precio_final += precio_promo
        lista_promociones.remove(promocion)
    for articulo, cantidad in carrito.items():#Para los productos sueltos: 
        if cantidad > 0:
            precio_unidad = diccionario_articulos[articulo]#toma el precio de cada unidad
            precio_articulo_final = precio_unidad * cantidad
            productos_sueltos.append(f"{articulo}, {cantidad}, {precio_unidad} - {precio_articulo_final}")#Agrega a la lista de los productos sueltos, el string con la informacion
            precio_final += precio_articulo_final
    return productos_sueltos,productos_promocion, precio_final

def imprimir_pantalla(productos_sueltos,productos_promocion,precio_final):#Funcion para imprimir en pantalla los resultados
    print("Promociones:")
    for promociones in productos_promocion:
        print(promociones)
    print("Articulos sueltos:")
    for articulos in productos_sueltos:
        print(articulos)
    print("Total:")
    print(precio_final)

def testing():
    assert(aplicar_promocion([('Aceite de girasol', 3, 'Suavizante', 1, 309), ('Manteca', 2, 'Aceite de girasol', 2, 9282), ('Fideos', 2, 'Lavandina', 2, 7332), ('Aceite de girasol', 2, 'Manzanas', 3, 10278), ('Yogur', 1, 'Leche', 2, 2969), ('Manzanas', 3, 'Mermelada', 1, 12060), ('Aceite de girasol', 3, 'Huevos', 3, 12686), ('Lentejas', 1, 'Manteca', 2, 7270)],{'Leche': 6, 'Yogur': 4, 'Cafe': 1, 'Aceite de girasol': 2, 'Arroz': 3, 'Lentejas': 1, 'Papel higienico': 4},{'Leche': 1200, 'Queso untable': 2350, 'Yogur': 1455, 'Arroz': 3500, 'Fideos': 959, 'Suavizante': 8240, 'Papel higienico': 5780, 'Servilletas': 4320, 'Manzanas': 3040, 'Bananas': 4320, 'Queso': 6500, 'Lentejas': 3200, 'Aceite de girasol': 2700, 'Aceite de oliva': 12600, 'Salchichas': 2300, 'Manteca': 3500, 'Sal': 2000, 'Lavandina': 6000, 'Huevos': 4300, 'Cafe': 7050, 'Mermelada': 5400, 'Dulce de leche': 5300})==(['Yogur, 1, 1455 - 1455', 'Cafe, 1, 7050 - 7050', 'Aceite de girasol, 2, 2700 - 5400', 'Arroz, 3, 3500 - 10500', 'Lentejas, 1, 3200 - 3200', 'Papel higienico, 4, 5780 - 23120'],['Yogur, 1 - Leche, 2 - 2969', 'Yogur, 1 - Leche, 2 - 2969', 'Yogur, 1 - Leche, 2 - 2969'],59632))
    assert(aplicar_promocion([('Lentejas', 1, 'Aceite de girasol', 2, 2823), ('Queso', 2, 'Queso untable', 1, 11781), ('Manteca', 2, 'Cafe', 1, 12295), ('Leche', 3, 'Dulce de leche', 1, 7441), ('Mermelada', 3, 'Dulce de leche', 1, 7774), ('Lavandina', 1, 'Leche', 3, 9350), ('Manteca', 2, 'Mermelada', 3, 7480), ('Cafe', 1, 'Salchichas', 1, 3374)],{'Leche': 6, 'Yogur': 4, 'Cafe': 1, 'Aceite de girasol': 2, 'Arroz': 3, 'Lentejas': 1, 'Papel higienico': 4},{'Leche': 1200, 'Queso untable': 2350, 'Yogur': 1455, 'Arroz': 3500, 'Fideos': 959, 'Suavizante': 8240, 'Papel higienico': 5780, 'Servilletas': 4320, 'Manzanas': 3040, 'Bananas': 4320, 'Queso': 6500, 'Lentejas': 3200, 'Aceite de girasol': 2700, 'Aceite de oliva': 12600, 'Salchichas': 2300, 'Manteca': 3500, 'Sal': 2000, 'Lavandina': 6000, 'Huevos': 4300, 'Cafe': 7050, 'Mermelada': 5400, 'Dulce de leche': 5300})==(['Leche, 6, 1200 - 7200', 'Yogur, 4, 1455 - 5820', 'Cafe, 1, 7050 - 7050', 'Arroz, 3, 3500 - 10500', 'Papel higienico, 4, 5780 - 23120'],['Lentejas, 1 - Aceite de girasol, 2 - 2823'],56513))

def main():
    archivo_articulos=input("Ingrese el nombre del archivo de articulos: ")
    archivo_carrito=input("Ingrese el nombre del archivo del carrito: ")
    articulos=leer_archivo(archivo_articulos)
    carrito=leer_archivo(archivo_carrito)
    promociones=leer_promociones("promociones.txt")
    funcion_aplicar=aplicar_promocion(promociones,carrito,articulos)
    imprimir_pantalla(funcion_aplicar[0],funcion_aplicar[1],funcion_aplicar[2])

if __name__=="__main__":
    testing()
    main()