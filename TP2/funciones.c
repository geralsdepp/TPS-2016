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
