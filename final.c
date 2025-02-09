#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct{
    int posx;
    int posy;
}Posicion;

typedef struct{
    Posicion inicio;
    Posicion objetivo;
    Posicion dimension;
    Posicion* obstaculos;
    int cant_aleatorios;
    Posicion obs_aleatorios;
}Datos_lab;

int cant_lineas(FILE *archivo_entrada){
    int contador=0;
    char buffer[10];
    while (fgets(buffer,sizeof(buffer),archivo_entrada)!=NULL)
    {
        contador++;
    }
    rewind(archivo_entrada);
    return contador;
}

Datos_lab leer_archivo(FILE *archivo_entrada,int lineas){
    Datos_lab info_lab;
    info_lab.inicio.posx=1;
    info_lab.inicio.posy=1;
    info_lab.cant_aleatorios=3;
    info_lab.obstaculos=malloc(sizeof(Posicion)*(lineas-2));
    assert(info_lab.obstaculos);
    fscanf(archivo_entrada,"%d %d\n",&info_lab.dimension.posx,&info_lab.dimension.posy);
    fscanf(archivo_entrada,"%d %d\n",&info_lab.objetivo.posx,&info_lab.objetivo.posy);
    assert(info_lab.objetivo.posx <= info_lab.dimension.posx);
    assert(info_lab.objetivo.posy <= info_lab.dimension.posy);
    for (int i = 0; i < lineas-2; i++)
    {
        fscanf(archivo_entrada,"%d %d\n",&(info_lab.obstaculos[i]).posx,&(info_lab.obstaculos[i]).posy);
        assert(info_lab.obstaculos[i].posx <= info_lab.dimension.posx);
        assert(info_lab.obstaculos[i].posy <= info_lab.dimension.posy);
    }
    return info_lab;
}

char **inicia_array(Datos_lab info){
    char **array_caracteres= malloc(sizeof(char*)*(info.dimension.posx));
    assert(array_caracteres);
    for (int i = 0; i < info.dimension.posy; i++)
    {
        array_caracteres[i]=malloc(sizeof(char)*info.dimension.posy);
        assert(array_caracteres[i]);
    }
    return array_caracteres;
} 

void llenado_libres(char** array_caracteres,Datos_lab info){
    for (int i = 0; i < info.dimension.posx; i++)
    {
        for (int j= 0; j < info.dimension.posy; j++)
        {
            array_caracteres[i][j]='0';

        }
    }
}

void llenado_fijos(char **array_caracteres,Datos_lab info,int lineas){
    for (int i = 0; i < lineas-2; i++)
    {
        array_caracteres[(info.obstaculos[i].posx)-1][(info.obstaculos[i].posy)-1]='1';
    }
    array_caracteres[(info.inicio.posx)-1][(info.inicio.posy)-1]='I';
    array_caracteres[(info.objetivo.posx)-1][(info.objetivo.posy)-1]='X';
}

void llenado_aleatorios(char** array_caracteres,Datos_lab info){
    int i=0;
    while (i<info.cant_aleatorios)
    {
        info.obs_aleatorios.posx= rand() % info.dimension.posx;
        info.obs_aleatorios.posy= rand() % info.dimension.posy;
        if(array_caracteres[info.obs_aleatorios.posx][info.obs_aleatorios.posy]=='0'){
            array_caracteres[info.obs_aleatorios.posx][info.obs_aleatorios.posy]='1';
            i++;
        }
    }
}

void escritura_archivo(FILE *archivo_llegada,char** array_caracteres,Datos_lab info){
    for (int i = 0; i < info.dimension.posx; i++)
    {
        for (int j = 0; j < info.dimension.posy; j++)
        {
            fputc(array_caracteres[i][j],archivo_llegada);
        }
        fputc('\n',archivo_llegada);
    }
    
}

int main(){
    FILE *archivo_datos=fopen("facil.txt","r");
    FILE *archivo_laberinto=fopen("laberinto.txt","w");
    int lineas=cant_lineas(archivo_datos);
    Datos_lab info_laberinto=leer_archivo(archivo_datos,lineas);
    char** array_posiciones=inicia_array(info_laberinto);
    llenado_libres(array_posiciones,info_laberinto);
    llenado_fijos(array_posiciones,info_laberinto,lineas);
    llenado_aleatorios(array_posiciones,info_laberinto);
    escritura_archivo(archivo_laberinto,array_posiciones,info_laberinto);
    fclose(archivo_datos);
    fclose(archivo_laberinto);
    free(info_laberinto.obstaculos);
    for (int i = 0; i < info_laberinto.dimension.posx; i++)
    {
        free(array_posiciones[i]);
    }
    free(array_posiciones);
    return 0;
}
