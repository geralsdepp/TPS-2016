#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

#define PERSONAS 20

int main()
{
    char aux_nombre[30], aux_edad[10], aux_DNI_STR[30], aux_ID;
    int lugar_libre, lugar_ocupado;
    long int aux_DNI;
    int i, getNum,  flag = 0, opcion = 0, ultimo_id = 0;

    Persona arrayPersonas[PERSONAS];

    iniciarDatosArray(arrayPersonas, PERSONAS, 0);

    while(opcion != 5)
    {
        opcion = getOpcion(opcion);

        switch(opcion)
        {
        case 1:
            lugar_libre = buscarPrimerOcurrencia(arrayPersonas, PERSONAS, -1);

            if(lugar_libre == -1)
            {
                printf("NO HAY MAS LUGARES LIBRES!!!\n");
                break;
            }
            else
                printf("ALTA\n");

            while(flag == 0)
            {
                if(!getStringNumeros("Ingrese el DNI: ", aux_DNI_STR))
                {
                    printf("El DNI debe ser numerico!!!\n");
                    break;
                }
                else
                {
                    flag = 1;
                }
            }
            aux_DNI = atol(aux_DNI_STR);

            flag = 0;

            while(flag == 0)
            {
                if(!getStringLetras("Ingrese nombre: \n", aux_nombre))
                {
                    printf("El nombre debe contener letras!!");
                    break;
                }
                else
                    flag = 1;
            }
            flag = 0;
            while(flag == 0)
            {
                if(getStringNumeros("Ingrese edad: \n",aux_edad))
                {
                    printf("La edad debe contener numeros!!");
                    break;
                }
                else
                    flag = 1;
            }
            flag = 0;

            arrayPersonas[lugar_libre].DNI = aux_DNI;
            arrayPersonas[lugar_libre].edad = aux_edad;
            strcpy(arrayPersonas[lugar_libre].nombre,aux_nombre);
            arrayPersonas[lugar_libre].idEstado = 1;
            ultimo_id = ultimo_id + 1;
            printf("PELICULA CARGADA!!");
            break;
        case 2:
            printf("BORRAR PERSONA");

            if(!getStringNumeros("Ingrese el ID que desee borrar: \n", aux_ID))
            {
                printf("El ID debe ser numerico!!");
                break;
            }
            getNum = atoi(aux_ID);

            lugar_ocupado = buscarIdPersonas(arrayPersonas, PERSONAS, getNum)

            printf("%d",lugar_ocupado);

            if(lugar_ocupado == -1)
            {
                printf("No se encuentra el código!!");
                break;
            }
            arrayPersonas[lugar_ocupado].idEstado = -1;
            break;
        case 3:
            for(i=0; i<PERSONAS;i++)
            {

            }
            break;
        case 4:
            break;
        case 5:
            break;
        }
    }
}
