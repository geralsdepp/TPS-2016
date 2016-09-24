#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "funciones.h"

 /** \brief busca lugar vacío en un array de personas
  * \param array es el array en el cual va a buscar
  * \param cantidad de elementos indica la longitud del array
  * \param valor es el valor que se busca
  * \return si no existe (-1) y si la hay, la posicion de la misma
  */

int buscarLugarVacio(Persona arrayPersonas[],int cantElement,int valor)
{
    int i;
    for(i=0;i<cantElement;i++)
    {
        if(arrayPersonas[i].DNI==valor)
        {
            return i;
        }
    }
    return -1;
}

/** \brief Inicializa un array de personas con el valor recibido
 * \param Array es el array a ser inicializado
 * \param cantElement indica la longitud del array.
 * \param valor es el valor a ser cargado en cada posicion
 * \return void
 *
 */
 void cargarPersonas(Persona arrayPersonas[],int cantElement,int valor)
 {
     int i;

     for(i=0;i<cantElement;i++)
     {
         arrayPersonas[i].DNI=valor;
     }
}

void mostrarGrafico(Persona arrayPersonas[])
{
    int i, hasta18=3, de19a35=5, mayorDe35=7, flag=0, mayor;

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }
    else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
            mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);

    return 0;
}
