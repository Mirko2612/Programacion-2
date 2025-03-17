#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nombre_articulo[50];
    int precio;
}Articulo;

typedef struct {
    Articulo art1;
    int n1;
    Articulo art2;
    int n2;
    int precio_promo;
}Promo;

Articulo* leer_articulos(FILE* archivo_entrada,int* cantidad_articulos) {//Articulos toma un archivo de entrada y un puntero a entero, crea un puntero a Articulo donde guarda los articulos del archivo
    int capacidad = 10;
    Articulo* lista = malloc(capacidad * sizeof(Articulo));
    assert(lista);
    *cantidad_articulos = 0;//cantidad articulos accede al puntero creado en el main para ser la cantidad de productos
    while (fscanf(archivo_entrada, "%49[^,],%d\n", lista[*cantidad_articulos].nombre_articulo, &lista[*cantidad_articulos].precio) == 2) {//Mientras lea 2 elementos del archivo,significa que hay un producto
        (*cantidad_articulos)++;
        if (*cantidad_articulos == capacidad) {
        capacidad *= 2;
        lista = realloc(lista, capacidad * sizeof(Articulo));
        assert(lista); 
        }
    }
    lista = realloc(lista,*cantidad_articulos * sizeof(Articulo));//Hago un realloc a su tamanio exacto
    fclose(archivo_entrada);
    return lista;
}

Promo generar_promo(Articulo* lista_articulos,int largo_lista){//generar_promo toma la lista de articulos con su largo y me genera una estructura tipo promo
    Promo promo;
    int indice1=rand()%largo_lista;
    int indice2=rand()%largo_lista;
    while (indice1==indice2)
    {
        indice2=rand()%largo_lista;//Si son 2 indices iguales genera uno nuevo
    }
    promo.art1=lista_articulos[indice1];
    promo.art2=lista_articulos[indice2];
    promo.n1=(rand()%3)+1;
    promo.n2=(rand()%3)+1;
    int precio_original=(promo.n1 * promo.art1.precio)+(promo.n2 * promo.art2.precio);//precio si compraria los productos sin promocion
    promo.precio_promo=1+(rand()% (precio_original)-1);
    return promo;    
}

void escritura_archivo(FILE* archivo_salida,int N,Articulo* lista_articulos,int cant_articulos){
    for (int i = 0; i < N; i++)
    {
        Promo promocion= generar_promo(lista_articulos,cant_articulos);
        fprintf(archivo_salida,"%s,%d,%s,%d,%d\n",promocion.art1.nombre_articulo,promocion.n1,promocion.art2.nombre_articulo,promocion.n2,promocion.precio_promo);
    }
    free(lista_articulos);
    fclose(archivo_salida);
}

int main(int argc, char* argv[]) {
    if (argc!=3)
    {
        printf("Cantidad incorrecta de argumentos\n");
        return 1;
    }
    srand(time(NULL));
    FILE* archivo_articulos=fopen(argv[1],"r");
    assert(archivo_articulos);
    FILE* archivo_promos=fopen("promociones.txt","w+");
    assert(archivo_promos);
    int N=atoi(argv[2]);
    int cant_articulos;
    Articulo* lista_articulos=leer_articulos(archivo_articulos,&cant_articulos);
    if (cant_articulos<2)
    {
        printf("Se necesitan al menos dos productos\n");
        return 1;
    }
    escritura_archivo(archivo_promos,N,lista_articulos,cant_articulos);
    return 0;
}