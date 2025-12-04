#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Firmas
void *functionHiloChar(void *argC);
void *functionHiloFloat(void *argF);
void *functionHiloDouble(void *argD);
//Fin Firmas

//Metodos
// Metodo Main
int main (){
    pthread_t hiloC;
    pthread_t hiloF;
    pthread_t hiloD;

    char *numeroChar = malloc(sizeof(char));
    *numeroChar = 'A'; 

    float *numeroFloat = malloc(sizeof(float));
    *numeroFloat = 5.5;

    double *numeroDouble = malloc(sizeof(double));
    *numeroDouble = 7.3;

    //Impresion de Los datos iniciales
    printf("Los datos iniciales son: \n");
    printf("Char: %c \n", *numeroChar);
    printf("Float: %f \n", *numeroFloat);
    printf("Double: %lf \n",*numeroDouble);
    //Fin impresion de los datos iniciales
    printf("\n");
    //Impresion de las operaciones a realizar
    printf("A los datos se le realizaran las siguientes operaciones: \n");
    printf("Char: %c + 1  \n", *numeroChar);
    printf("Float: %f  + 1.5 \n", *numeroFloat);
    printf("Double: %lf + 3.5 \n",*numeroDouble);
    //Fin impresion de operaciones a realizar
    printf("\n");

    pthread_create(&hiloC, NULL, functionHiloChar, (void *)numeroChar);
    pthread_create(&hiloF,NULL, functionHiloFloat, (void *) numeroFloat);
    pthread_create(&hiloD, NULL, functionHiloDouble, (void *) numeroDouble);

    void *resultadoHiloChar;
    pthread_join(hiloC, &resultadoHiloChar);

    void *resultadoHiloFloat;
    pthread_join(hiloF, &resultadoHiloFloat);

    void *resultadoHiloDouble;
    pthread_join(hiloD, &resultadoHiloDouble);

   

    //Impresion de Datos de los Hilos
    char resultadoC = *(char *)resultadoHiloChar;
    printf("Main: resultado recibido hilo Char = %c \n", resultadoC);

    float resultadoF = *(float *)resultadoHiloFloat;
    printf("Main: resultado recibido hilo Float = %f \n", resultadoF);

    double resultadoD = *(double *)resultadoHiloDouble;
    printf("Main: resultado recibido hilo Double = %lf \n", resultadoD);
    //Fin impresion de datos de los hilos

    free(resultadoHiloChar);
    free(resultadoHiloDouble);
    free(resultadoHiloFloat);

    return 0;
}
//Fin Metodo main

//Hilo char
void *functionHiloChar(void *argC){
    char *ptr = (char *)argC;
    char resultado = *ptr + 1;  //De este modo se cambiara 'A' -> 'B'

    char *res = malloc(sizeof(char));
    *res = resultado; 

    free(ptr);
    return (void *)res;
}
//Fin hilo Cahr

//hilo float
void *functionHiloFloat(void *argF){
    float *ptr = (float *) argF;
    float resultado  = *ptr + 1.5;

    float *res = malloc(sizeof(float));
    *res = resultado;

    free(ptr);
    return (void *)res;
}
//Fin hilo float

//Hilo Double
void *functionHiloDouble(void *argD){
    double *ptr = (double *) argD;
    double resultado  = *ptr + 3.5;

    double *res = malloc(sizeof(float));
    *res = resultado;

    free(ptr);
    return (void *)res;
}
//Fin hilo Double

//Fin Metodos