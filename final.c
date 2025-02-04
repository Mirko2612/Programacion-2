#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int posx;
    int posy;
}Posicion;

typedef struct
{
    Posicion dimension;
    Posicion inicio;
    Posicion objetivo;
    Posicion *obstaculos;
}Datos_lab;



int cant_lineas(FILE *nombre_archivo){
    int contador = 0;
    char buffer[25]; 
    while (fgets(buffer, sizeof(buffer), nombre_archivo) != NULL) {
        contador++;}
    rewind(nombre_archivo);

    return contador-1;    
}

Datos_lab leer_laberinto(FILE *nombre_archivo, Datos_lab lab,int lineas){
    lab.inicio.posx=1;
    lab.inicio.posy=1;
    lab.obstaculos = malloc(sizeof(Posicion)*(lineas-1));
    fscanf(nombre_archivo,"%d %d\n",&lab.dimension.posx,&lab.dimension.posy);
    fscanf(nombre_archivo,"%d %d\n",&lab.objetivo.posx,&lab.objetivo.posy);
    for (int i = 0; i < lineas-1; i++)
    {
        fscanf(nombre_archivo,"%d %d\n",&(lab.obstaculos[i]).posx,&(lab.obstaculos[i]).posy);
    }
    return lab;
}

char **inicia_lab(Datos_lab info){
    char** array_caracteres= malloc(sizeof(char*)*(info.dimension.posx));
    assert(array_caracteres);
    for (int i = 0; i < info.dimension.posx; i++)
    {
        array_caracteres[i]=malloc(sizeof(char)*(info.dimension.posy));
        assert(array_caracteres[i]);
    }
    return array_caracteres;
}

void llenado_libres(char **arreglo_c,Datos_lab info){
    for (int i = 0; i < info.dimension.posx; i++)
    {
        for (int j = 0; j < info.dimension.posy; j++)
        {
            arreglo_c[i][j]='0';
        }
    }
}

void llenado_obsymeta(char**arreglo_c,int tamanio_lab,Datos_lab info){
    for (int i = 0; i <= tamanio_lab-2; i++)
    {
       arreglo_c[(info.obstaculos[i].posx)-1][(info.obstaculos[i].posy)-1]='1';
    }
    arreglo_c[(info.objetivo.posx)-1][(info.objetivo.posy)-1]='X';
    arreglo_c[(info.inicio.posx)-1][(info.inicio.posy)-1]='I';
}
void escritura_archivo(char **arreglo_c,Datos_lab info,FILE *archivo_llegada){
    for (int i = 0; i < info.dimension.posx; i++)
    {
        for (int j = 0; j < info.dimension.posy; j++)
        {
            fputc(arreglo_c[i][j],archivo_llegada);
        }
        fputc('\n',archivo_llegada);
    }
    
}

int main(){
    Datos_lab laberinto;
    FILE *archivo_datos=fopen("facil.txt","r+");
    FILE *archivo_laberinto=fopen("laberinto.txt","w+");
    int lineas =cant_lineas(archivo_datos);
    laberinto = leer_laberinto(archivo_datos,laberinto,lineas);
    char**arreglo_caracteres= inicia_lab(laberinto);
    llenado_libres(arreglo_caracteres,laberinto);
    llenado_obsymeta(arreglo_caracteres,lineas,laberinto);
    escritura_archivo(arreglo_caracteres,laberinto,archivo_laberinto);
    
    free(laberinto.obstaculos);
    for (int i = 0; i <= laberinto.dimension.posx; i++) {
    free(arreglo_caracteres[i]);
    }
    free(arreglo_caracteres);
    fclose(archivo_datos);
    fclose(archivo_laberinto);
    return 0;
}  
