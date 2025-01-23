#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//#1
void prueba(){
    int a = 24;
    char b[] = "hola";
    printf("%p \n", &a);
    printf("%p %p %p %p \n",&b[0], &b[1], &b[2], &b[3] );
}
//#2
void setzerozero(int a[]){
    printf("%d %p \n", a[0],a);
    a[0] = 0;
    printf("%d %p \n", a[0],a);
}

//#3
void setin(int* i){
    if (*i ==0){
        *i=0;
    }
    else{
        *i=1;
    }
    printf("%d\n",*i);
}

//#4
void swap(int* a,int* b){
    int valor1 = *a;
    int valor2 = *b;
    *a = valor2;
    *b = valor1;
    printf("%d %d \n", *a,*b);

}

//#6
char* newgetline(){
    int i=0;
    int size=10;    
    char* cadena=malloc(sizeof(char)*size);
    assert(cadena != NULL);
    cadena[0]=getchar();
    while (cadena[i]!= '\n')
    {
        i++;
        if(i==size){
            size=i*2;
            cadena=realloc(cadena,size);
            assert(cadena != NULL);
        }
        cadena[i]=getchar();

    }
    cadena[i]='\0';
    cadena=realloc(cadena,i+1);
    printf("%s\n", cadena);
    return cadena;
}

//#7
int* free_doble(){
    int* a= malloc(100);
    *a= 2;
    printf("%p",a);
    free(a);
    free(a);
    return 0;
}

//#8
//a)
int sumados(int n){
    n= n+2;
    return n;
}

int (*op_matematica)(int);

//#10
typedef struct{
    short palo;
    short valor;
}Carta;

Carta azar(Carta mazo[],int tam){
    return mazo[(rand()%tam)];
}

//#11
typedef struct{
    short x;
    short y;
}Punto;

Punto medio(Punto p1,Punto p2){
    Punto punto_medio;
    punto_medio.x=(p1.x +p2.x)/2;
    punto_medio.y=(p1.y +p2.y)/2;
    return punto_medio;
}

//#12
typedef struct{
    char *Nombre;
    char *Num;
    unsigned char Edad;
}Contacto;

Contacto *crear_contacto(){
    Contacto *contacto1;
    contacto1=malloc(sizeof(Contacto));
    char nombre[20];
    char num[30];
    unsigned int temp;
    unsigned char edad;

    printf("Ingrese el nombre de la persona: ");
    scanf("%s",nombre);
    contacto1->Nombre=malloc(sizeof(char)*(strlen(nombre)+1));
    strcpy(contacto1->Nombre,nombre);

    printf("Ingrese el numero de la persona: ");
    scanf("%s",num);
    contacto1->Num=malloc(sizeof(char)*(strlen(num)+1));
    strcpy(contacto1->Num,num);
    
    printf("Ingrese la edad de la persona: ");
    scanf("%u",&temp);
    edad=(unsigned char)temp;
    contacto1->Edad=edad;
    return contacto1;
}
void liberar_contacto(Contacto *c1){
    free (c1->Nombre);
    free (c1->Num);
    free(c1);
}




int main(){
    //prueba();
    //int arr1[]= {4,5,7,1,3};
    //setzerozero(arr1);
    //int a=15;
    //int b=0;
    //setin(&a);
    //setin(&b);
    //swap(&a,&b)
    //char* a= newgetline();
    //free(a);
    //free_doble();
    //op_matematica = sumados;
    //int resultado= op_matematica(2);
    //printf("%d\n",resultado);
    /*Carta mazo[48];
    int index=0;
    for (int i = 1; i <=4; i++)
    {
        for (int j = 1; j <13 ; j++)
        {
            mazo[index].palo=i;
            mazo[index].valor=j;
            index++;
        }
        
    }
    printf("%d\n",mazo[0].palo);
    Carta carta_elegida=azar(mazo,48);
    printf("%d %d\n",carta_elegida.palo,carta_elegida.valor);*/
    /*Punto p1;
    p1.x=3;
    p1.y=-1;
    Punto p2;
    p2.x=7;
    p2.y=1;
    Punto p_medio=medio(p1,p2);
    printf("%d %d\n",p_medio.x,p_medio.y);*/
    //Contacto *contac1= crear_contacto();
    //printf("El nombre del contacto es:%s\nEl numero de la persona es:%s\nLa edad de la persona es: %d",contac1->Nombre,contac1->Num,contac1->Edad);
    //liberar_contacto(contac1);
    return 0;
}