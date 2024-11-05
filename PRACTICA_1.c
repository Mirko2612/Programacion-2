#include <stdio.h>

//#4 Escriba una función que determine en qué estado está el agua en función de su temperatura: si es negativa o 0 el estado será sólido, si positiva y menor que 100 será líquido 
//y si es mayor que 100 será gaseoso
void estado_agua(float t){
    if (t < 0){
        printf("El estado es solido\n");
    }
    else if (t>=0 && t<100){
        printf("El estado es liquido\n");
    }
    else{
        printf("El estado es gaseoso\n");
    }
}   

//#5 Escriba una función que lea la nota de un alumno (entera) y muestre un mensaje diciendo si sacó insifuciente (2 a 5), aprobado (6), bueno (7), muy bueno (8), distinguido (9) o sobresaliente (10).
void analizarnota(int nota){
    if ((nota <= 5) && (nota>= 2)){
        printf("Insuficiente\n");        
    }if (nota == 6){
        printf("Aprobado\n");
    }if (nota == 7){
        printf("Bueno\n");
    }if (nota == 8){
        printf("Muy bueno\n");
    }if (nota == 9){ 
        printf("Distinguido\n");
    }if (nota == 10){
        printf("Sobresaliente\n");
    }
}

//#6 Construya un programa que lea por teclado el día y mes de nacimiento de una persona como números enteros y calcule su signo del zodíaco, mostrándolo por pantalla.
void signozodiacal(int dia, int mes){
    if ((dia >=21 && mes ==3)||(dia<=19 && mes==4)){
        printf("tu signo es de Aries\n");
    }
    else if ((dia >=20 && mes ==4)||(dia<=20 && mes==5)){
        printf("tu signo es de Tauro\n");
    }
    else if ((dia >=21 && mes ==5)||(dia<=21 && mes==6)){
        printf("tu signo es de Geminis\n");
    }
    else if ((dia >=22 && mes ==6)||(dia<=21 && mes==7)){
        printf("tu signo es de Cancer\n");
    }
    else if ((dia >=22 && mes ==7)||(dia<=21 && mes==8)){
        printf("tu signo es de Leo\n");
    }
    else if ((dia >=22 && mes ==8)||(dia<=22 && mes==9)){
        printf("tu signo es de Virgo\n");
    }
    else if ((dia >=23 && mes ==9)||(dia<=22 && mes==10)){
        printf("tu signo es de Libra\n");
    }
    else if ((dia >=23 && mes ==10)||(dia<=21 && mes==11)){
        printf("tu signo es de Escorpio\n");
    }
    else if ((dia >=22 && mes ==11)||(dia<=21 && mes==12)){
        printf("tu signo es de Sagitario\n");
    }
    else if ((dia >=22 && mes ==12)||(dia<=20 && mes==1)){
        printf("tu signo es de Capricornio\n");
    }
    else if ((dia >=21 && mes ==1)||(dia<=19 && mes==2)){
        printf("tu signo es de Acuario\n");
    }
    else if ((dia >=20 && mes ==2)||(dia<=20 && mes==3)){
        printf("tu signo es de Piscis\n");
    }
}

//#7 Escriba un programa que lea por teclado un año y devuelva si es bisiesto o no
void bisciesto(int anio){
    if(anio%400 == 0 || (anio%4 ==0 && anio%100 !=0)){
        printf("Bisciesto\n");
    }
    else{
        printf("No bisciesto\n");
    }
}

//#9 Escriba un programa que muestre los números enteros del 1 al 100.
void unoal100(){
    int x=0;
    while (x<=100)
    {
        printf("%d\n",x);
        x=x+1;
    }
    
}

//#10 Escriba un programa que muestre los números impares del 1 al 100.
void impares_al100(){
    int x=0;
    while (x<=100)
    {
        if (x%2!=0){
            printf("%d\n",x);
        }
        x=x+1;
    }   
}

//#11 Escriba un programa que pida dos números por teclado y muestre todos los números que van desde el primero hasta el segundo.
void num_entre(){
    int x,y;
    printf("Ingrese 2 numeros: ");
    scanf("%d %d",&x,&y);
    while(x>y){
        printf("El primer numero debe ser menor al segundo\n");
        printf("Ingreselos nuevamente: ");
        scanf("%d %d",&x,&y);
    }
    while(x<y){
        printf("%d \n",x);
        x=x+1;
    }
}

//#12 Escriba un programa que, dado un número ingresado por teclado, determine si el mismo es primo o no, mostrándolo por pantalla
void esprimo(){
    int x;
    int y=1;
    int c=0;
    printf("Ingrese un numero para ver si es primo: ");
    scanf("%d",&x);
    while (y<=x)
    {
        if(x%y==0){
            c=c+1;
        }
        y=y+1; 
    }
    if(c>2){
            printf("No es primo\n");
        }
        else{
            printf("Es primo\n");
        }
}

//#13 Escriba un programa que lea un número por teclado y muestre el factorial del mismo
double factorial(){
    int x;
    double y=1;
    printf("Ingrese un numero para ver su factorial: ");
    scanf("%d",&x);
    while (x<1)
    {
        printf("Ingrese un numero positivo: ");
        scanf("%d",&x);
    }

    while (x!=1)
    {
        y=y*x;
        x=x-1;
    }
    return y;
}

//#14  Escriba un programa en C que lea desde el teclado el número de pacientes a analizar seguido de la edad y el índice de cada paciente
void pacientes(){
    int cant_total=0,cant_ingre=0,cant_operados=0,x=0,edad_ingre=0,edad_oper=0,edad=0;
    float medicion=0,media_ingre,media_oper;
    printf("Ingrese la cantidad de pacientes a analizar: ");
    scanf("%d",&cant_total);
    while (x<cant_total)
    {
        printf("Ingrese la edad seguido de la medicion: ");
        scanf("%d %f",&edad,&medicion);
        if (medicion>= 0.6 && medicion<=0.9){
            edad_ingre=edad_ingre+edad;
            cant_ingre++;
        }
        else if (medicion >0.9){
           edad_oper=edad_oper+edad;
           cant_operados++;
        }
        edad=0;
        x=x+1;
    }

    media_ingre = edad_ingre / cant_ingre;
    media_oper = edad_oper / cant_operados;
    printf("La edad media de los ingresados es de: %.1f \n",media_ingre);
    printf("La edad media de los operados es de: %.1f \n",media_oper);
    
}

//#15 Escriba una función maximo que tome como parámetros dos enteros y devuelva el máximo entre ellos.
int maximo(int a, int b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}

//#16 Escriba y pruebe una función ladosTriangulo que devuelva 1 si los tres números que se le pasan verifican esta condición o 0 en caso contrario
int maximo3(int a, int b, int c){
    if (a>b && a>c){
        return a;
    }
    else if (b>a && b>c){
        return b;
    }
    else{
        return c;
    }
    
}
int lados_triangulo(int a,int b,int c){
    int maximo= maximo3(a,b,c);
    if (maximo==a && (maximo< b+c)){
        return 1;
    }
    else if (maximo==b && (maximo< a+c)){
        return 1;
    }
    else if (maximo==c && (maximo < b+a)){
        return 1;
    }
    else{
        return 0;
    }
}

//#17 Defina una función esRectangulo que tome tres enteros y devuelva 1 si los números que se le pasan pueden ser los lados de un triángulo rectángulo, o 0 en caso contrario.
int esrectangulo(int a, int b, int c){
    int maximo= maximo3(a,b,c);
    if (maximo==a && (maximo*maximo< b*b+c*c)){
        return 1;
    }
    else if (maximo==b && (maximo*maximo< a*a+c*c)){
        return 1;
    }
    else if (maximo==c && (maximo*maximo < b*b+a*a)){
        return 1;
    }
    else{
        return 0;
    }
}

//#18 Escriba un programa que lea un año y muestre el día y el mes en el que se celebró o se celebrará el domingo de Pascua ese año
float pascua(int anio){
    int A,B,C,D,E,N;
    A= anio% 19;
    B= anio% 4;
    C= anio% 7;
    D= (19*A + 24) % 30;
    E= (2*B + 4*C + 6*D +5) % 7;
    N= (22 + D + E);
    if (N>31){
        return N-31;
    }
    else{
        return N;
    }

} 

//#19 Escriba una función recursiva f que tome un entero n y devuelva el correspondiente valor según la sucesión de Fibonacci.
int fibonacci(int n){
    if (n==0){
        return 0;
    }
    else if (n==1){
        return 1;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }

}

// Main or testing block
int main(){
    /*
    float t;
    int dia,mes;
    int num1, num2, num3,num4;
    int max1= maximo(num1,num2);
    int max2= maximo(num3,num4);
    int max_total= maximo(max1,max2);

    printf("Ingrese la temperatura del agua: ");
    scanf("%f",&t);
    estado_agua(t);
    analizarnota(6);
    printf("Ingrese su fecha de nacimiento (dia espacio mes): ");
    scanf("%d %d", &dia, &mes);
    signozodiacal(dia,mes);
    unoal100();
    impares_al100();
    num_entre();
    esprimo();
    printf("%.0f\n",factorial());
    pacientes();
    printf("Ingrese 4 numeros enteros para ver su maximo: ");
    scanf("%d %d %d %d",&num1,&num2,&num3,&num4);
    printf("Maximo total: %d",max_total);
    printf("%d\n",lados_triangulo(3,5,4));
    printf("%.0f \n",pascua(2025));
    printf("%d\n",fibonacci(25)); */
    
    return 0;
}

