#include <stdio.h>
#include <string.h>
#define num_secreto 357
//#1 Escriba un programa que pida por teclado el resultado obtenido al lanzar un dado de seis caras y muestre por pantalla el número en letras de la cara opuesta al resultado obtenido
void dados(int num){
    switch (num)
    {
    case 1:
        printf("Seis\n");
        break;
    case 2:
    printf("Cinco\n");
    break;
    case 3:
        printf("Cuatro\n");
        break;
    case 4:
        printf("Tres\n");
    break;
    case 5:
        printf("Dos\n");
        break;
    case 6:
        printf("Uno\n");
    break;
    default:
        printf("El Numero ingresado no es valido\n");
        break;
    }
}

//#2 Se pide que escriba un programa que: 1. Muestre el listado de las habitaciones de la casa de campo. 2. Pida por teclado el número (dato entero) asociado a una habitación.
//3. Muestre por pantalla la planta y el número de camas de la habitación seleccionada.
void habitaciones(){
    printf("1.Azul\n2.Roja\n3.Verde\n4.Rosa\n5.Gris\n");
    int n;
    printf("Ingrese el numero de habitacion: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("La habitacion Azul esta en la primera planta y tiene 2 camas.\n");
        break;
    case 2:
        printf("La habitacion Roja esta en la primera planta y tiene 1 camas.\n");
        break;
    case 3:
        printf("La habitacion Verde esta en la segunda planta y tiene 3 camas.\n");
        break;
    case 4:
        printf("La habitacion Rosa esta en la segunda planta y tiene 2 camas.\n");
        break;
    case 5:
        printf("La habitacion Gris esta en la tercera planta y tiene 1 camas.\n");
        break;
    default:
        printf("Numero no asociado a ninguna habitacion");
        break;
    }
}

//#3 Representando sumatorias
float sumatoria1(){
    float n = 0;
    for(int m=1;m<=100;m++){
        n += 1./m;
    }
  return n;
}

double sumatoria2(){
    double n = 0.;
    for(int m=1;m<=30;m++){
        n += 1.0/(m*m);
    }
  return n;
}
//
double potencia(double n){
    double f=n;
    for(double m=1;m<f;m++){
        n = n*f;
    }
    return n;
}

double sumatoria3(){
    double n = 0.;
    for(int m=1;m<=25;m++){
        n += 1.0/potencia(m);
    }
  return n;
} 

//#4 Escriba un programa que imprima todas las ternas pitagóricas con a ≤ 20 y b ≤ 30.
void ternapitagorica(){
    for(int a=0;a<=20;a++){
        for(int b=0;b<=30;b++){
            printf("%d \n",(a*a+b*b));
        }
    }
}

//#5 Escriba un programa que tenga un número secreto entre 0 y 500, el cual estará fijo en el código, el usuario tendrá un maximo de 15 intentos
void secreto(){
    int intento =-1;
    for(int intentos=0;intentos !=15 || intento != num_secreto;intentos++){
        printf("Ingrese el numero: ");
        scanf("%d",&intento);
        if (intento < num_secreto){
            printf("El numero secreto es mayor al ingresado, intente nuevamente\n");
        }
        else{
            printf("El numero secreto es menor al ingresado, intente nuevamente\n");
        }
    }
    if (intento==num_secreto)
    {
        printf("Felicidades adivinaste el numero secreto: %d\n",num_secreto);    
    }
    else{
    printf("No pudiste adivinar el numero secreto, este era: %d\n",num_secreto);
    }
}

//#6 Mediante una única instrucción for y un printf genere la siguiente salida. Emplee 3 variables: una para la cadena de texto, un entero y un char:
void letras(){
    for(int num=5,num2=1,num3=84;num>0;num2++, num-- , num3--){
        char palabra[5] = "bucle";
        palabra[num2] = '\0' ;
        printf("%s %d %c\n",palabra, num , num3);
        
        if (num3%2 == 0){
            num3 =num3 + 32;
        }
        else{
            num3 = num3 - 32;
        }
    }
}

//#7 Escriba un programa que lea un valor positivo y haga la siguiente secuencia: si el número es par, debe dividirlo entre 2; si es impar, debe multiplicarlo por 3 y sumarle 1. 
//La secuencia debe repetirse hasta que el valor sea 1, imprimiendo cada valor. También se deberá imprimir cuántas operaciones de estas fueron realizadas.
void conjetura(){
    int numero,contador=0;
    printf("Ingrese un numero mayor a 1: ");
    scanf("%d",&numero);
    for(int i=numero;i!=1;){
        if(i%2==0){
            i=i/2;}
        else{
            i=i*3 +1;}
       printf("el valor siguiente es: %d\n",i);
       contador++;
    }
    printf("Numero de pasos: %d\n",contador);
}

//#8 Escriba un programa que llene un arreglo con los primeros 100 números enteros a partir del 0 y los muestre en pantalla en orden ascendente.
void primeroscien(){
    int arreglo[100];
    for(int i=0;i<=100;i++){
        arreglo[i]=i;
        printf("%d,",arreglo[i]);
    }
    printf("\n");
}

//#9 Escriba un programa que llene un arreglo con los números pares que se encuentren entre 100 y 200 y los muestre en pantalla en orden descendente.
void cienpares(){
    int arreglo[51];
    for(int i=50;i>=0;i--){
        arreglo[i]= (i*2)+100;
        printf("%d\n,",arreglo[i]);
    }
    printf("\n");
}

//#10 Escriba un programa que llene un arreglo con los primeros 50 múltiplos de 3 y los muestre en pantalla en orden descendente.
void multiplos3(){
    int arreglo[51];
    for(int i=50;i>=0;i--){
        arreglo[i]= 3*i;
        printf("%d,",arreglo[i]);
    }
    printf("\n");
}

//#11 Escriba un programa que lea un arreglo a de 10 enteros y un entero n e imprima el índice del arreglo a donde se encuentra n si n está presente en el arreglo, o -1 en caso contrario
void arregloN(int n, int arr[]){
    int resultado = -1;
    for(int i=0;i<10;i++){
        if (arr[i]==n){
            resultado = i;
        }
    }
    printf("%d \n", resultado);
}

//#12 scriba un programa que lea un entero n entre 5 y 100 y luego solicite al usuario el ingreso de n enteros, los cuales debe guardar en un arreglo. 
//Finalmente, debe determinar si la suma de los elementos del arreglo es mayor a 30
void n_enteros(){
    int tam_arreglo,suma_nums=0;

    printf("Ingrese un entero entre 5 y 100: ");
    scanf("%d",&tam_arreglo);
    if(tam_arreglo<5 || tam_arreglo>100){
        printf("Error");
    }
    else{
        int a[tam_arreglo];
        for(int i=0;i<tam_arreglo;i++){
            printf("Ingrese un entero: ");
            scanf("%d",&a[i]);
            suma_nums= suma_nums+a[i];
        }
        if(suma_nums>30){
            printf("La suma %d es mayor a 30\n",suma_nums);
        }
        else{
            printf("La suma %d no es mayor a 30\n",suma_nums);
        }
    }
}

//#13 4. Escriba un programa que lea enteros hasta que se ingrese un número negativo y posteriormente imprima qué valor entre 0 y 99 se ingresó más veces
void enteros_neg(){
    int entero=0,comparar=0,devolver=0;
    int claves[100];
    for(int i=0;i<100;i++){
        claves[i]=0;
    }
    while(entero>=0){
        printf("Ingrese un numero: ");
        scanf("%d",&entero);
        claves[entero]=claves[entero]+1; 
    }
    for(int i=0;i<100;i++){
        if(claves[i]>=comparar){
            comparar=claves[i];
            devolver=i;
        }
    }
    printf("%d\n",devolver);
}

//#14 Escriba una función sumaArr que tome un arreglo de enteros junto con la longitud del mismo y devuelva la suma de sus elementos
void sumaArr(int Lon,int Arr[]){
    int suma=0;
    for(int i=0;i<Lon;i++){
        suma = suma + Arr[i];
    }
    printf("%d\n",suma); 
} 

//#15 Escriba una función prodAlt que tome un arreglo de enteros junto con la longitud del mismo y devuelva el producto de los elementos cuyos índices son pares. 
void prod_pares(int Lon,int Arr[]){
    int prod=1;
    for(int i=0;i<Lon;i++){
        if(i%2 ==0){
            prod = Arr[i]*prod; 
        }
    }
    printf("%d\n",prod);
}

//#16 Escriba una función que reciba una cadena de caracteres y un caracter y devuelva 0 si el caracter esta presente en la cadena, o 1 en caso contrario.
int c_in_string(char Arr[], char c){
    int esta=1;
    for(int i=0;i < strlen(Arr);i++){
        if(Arr[i]== c){
            esta=0;
        }
    }
    printf("%d\n",esta);
    return esta;
}

//#17 Escriba una función que reciba una cadena de caracteres y un caracter y devuelva la cantidad de apariciones del caracter en la cadena dada.
int apariciones(char Arr[], char c){
    int cont=0;
    for(int i= strlen(Arr);i>=0;i--){
        if(Arr[i]== c){
            cont++;
        }
    }
    printf("%d\n",cont);
    return cont;
}

//#18 Escriba un programa que lea por teclado una cadena de caracteres y la imprima por pantalla al revés
void al_reves(){
    char Arr[5];
    char ArrAlreves[5];
    printf("Ingrese una palabra: ");
    scanf("%s",Arr);
    for(int i=0;i<strlen(Arr);i++){
        ArrAlrevez[i]=Arr[strlen(Arr)-i-1];
    }
    printf("%s\n",ArrAlreves);
}

//#19 Escriba una función que reciba una cadena de caracteres y determine si la misma es capicúa.
void capicua(char Arr[]){
    int verdad=1;
    int largo=strlen(Arr);
    for(int i=0;i<largo;i++){
        if(Arr[i]!=Arr[largo-i-1]){
            verdad=0;
        } 
    }
    if(verdad==1){
        printf("Verdadero\n");
    }
    else
    {printf("Falso\n");
    }
}

//#20 Escriba una función que reciba una cadena de caracteres y determine si es un pangrama
int pangrama(char* cadena){
    int falta_letra=0;
    for (char letra='a';letra <='z' && !falta_letra;letra++){
        int tengo_letra=0;
        for(int i=0;cadena[i] != '\0' && !tengo_letra;i++){
            if(cadena[i]==letra){
                tengo_letra=1;
            }
        }
        if (!tengo_letra){
            falta_letra=1;
        }
    }
    return !falta_letra;   
}

//#21 Escriba una función que reciba dos cadenas de caracteres y determine si una está contenida dentro de la otra
void contenida(char Arr[], char Arr2[]){
  int cont=0;
  int largo_pal1= strlen(Arr);
  int largo_pal2= strlen(Arr2);
    for(int j=0; j<largo_pal2;j++){
        if(Arr[cont]==Arr2[j]){
            cont++;
            
            if(cont==largo_pal1){
                printf("Contenida\n");
            }
        }
        else{
            cont=0;
        }

  }
  
}

//main
int main(){
    return 0;
}



