#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"

/*Calculadora con las 4 funciones básicas*/

void main()
{
    float num1,num2,resultado;
    char seleccion;
    int band=0;

    printf("CALCULADORA BASICA"); //presentacion

    while(band==0)
    {
    //  \n  baja una linea

    MostrarMenu();
    scanf("%c",&seleccion);

    switch(seleccion)
    {
        case '1':
            //realizar la logica de la operación 1
            printf("selecciono opcion 1\n");
            break;
        case '2':
            //realizar la logica de la operación 2
            printf("selecciono opcion 2\n");
            break;
        case '3':
            printf("Salgo de mi programa\n");
            band = 1;
            break;
        default:
            //todos los otros valores
            printf("\nSelecciones una opcion valida!! soquete..\n");
    }

    }



    // esto para que lo pusiste?
    //return 0;

}

void MostrarMenu ()
{
    char sel;
    printf("\nSeleccione una opcion con el numero correspondiente:");
    printf("\nOpción 1");
    printf("\nOpción 2");
    printf("\nsalir\n");


    // devolver lo seleccionado
    //return 'sel';

}
