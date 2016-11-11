#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

#define PERSONAS 20

int main()
{
    char aux_nombre[30], aux_edad_STR[10], aux_DNI_STR[30], aux_ID[30];
    int lugar_libre, lugar_ocupado;
    long int aux_DNI;
    int aux_edad;
    int i, getNum,  flag = 0, opcion = 0, ultimo_id = 0;
    int menor18 = 0, de18a35 = 0, mayor35 = 0;

    Persona arrayPersonas[PERSONAS];

    iniciarDatosArray(arrayPersonas, PERSONAS, 0);

    while(opcion != 5)
    {
        opcion = getOpcion(opcion);
        system("cls");
        switch(opcion)
        {
        case 1:
            system("cls");
            lugar_libre = buscarPrimerOcurrencia(arrayPersonas, PERSONAS, -1);

            if(lugar_libre == -1)
            {
                printf("NO HAY MAS LUGARES LIBRES!!!\n");
                system("cls");
                break;
            }
            else
                printf("ALTA\n");

                system("cls");

            while(flag == 0)
            {
                if(!getStringNumeros("Ingrese el DNI: \n", aux_DNI_STR))
                {
                    fflush(stdin);
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
                if(!getStringLetras("Ingrese nombre: \n",aux_nombre))
                {
                    printf("El nombre debe contener letras!!\n");
                    break;
                }
                else
                    flag = 1;
            }
            flag = 0;
            while(flag == 0)
            {
                if(!getStringNumeros("Ingrese edad: \n",aux_edad_STR))
                {
                    printf("La edad debe contener numeros!!\n");
                    break;
                }
                else
                    flag = 1;
            }
            aux_edad = atoi(aux_edad_STR);
            flag = 0;

            arrayPersonas[lugar_libre].DNI = aux_DNI;
            arrayPersonas[lugar_libre].edad = aux_edad;
            strcpy(arrayPersonas[lugar_libre].nombre,aux_nombre);
            arrayPersonas[lugar_libre].idEstado = 1;
            ultimo_id = ultimo_id + 1;
            printf("PELICULA CARGADA!!\n");
            system("cls");
            break;
        case 2:
            system("cls");
            printf("BORRAR PERSONA\n");

            if(!getStringNumeros("Ingrese el ID que desee borrar: \n", aux_ID))
            {
                printf("El ID debe ser numerico!!\n");
                break;
            }
            getNum = atoi(aux_ID);

            lugar_ocupado = buscarIdPersonas(arrayPersonas, PERSONAS, getNum);

            printf("%d",lugar_ocupado);

            if(lugar_ocupado == -1)
            {
                printf("No se encuentra el código!!\n");
                break;
            }
            arrayPersonas[lugar_ocupado].idEstado = -1;
            break;

        case 3:
            system("cls");
            printf("IMPRIMIR LISTA ORDENADA POR NOMBRE\n");
            ordenarNombres(arrayPersonas,PERSONAS);
            for(i=0;i<PERSONAS;i++)//ciclo q muestra los nombres ya ordenados q aparecera en pantalla
            {
                   printf("%d --->%s\n",i+1,arrayPersonas[i].nombre);
            }
            break;
        case 4:
            system("cls");
            contarEdades(arrayPersonas,PERSONAS,&menor18,&de18a35,&mayor35);

            mostrarGrafico(menor18, de18a35, mayor35);

            break;
        case 5:
            printf("SALIR");
            break;
        }


    }

    return 0;
}
