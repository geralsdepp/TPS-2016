#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

#define PERSONAS 20

int main()
{
    //ARRAYS DE PERSONAS
    Persona arrayPersonas[PERSONAS];
    //////////////////////////////////////////////////////////////
    Persona auxPersona;

    char auxNombre[50];
    char auxDNI[20];
    int auxEdad;
    int aux2DNI;
    int i,j;


    int indiceLibre;
    int resultadoBusqueda;


    int opcion = 0;

    cargarPersonas(arrayPersonas,PERSONAS,-1);

    while(opcion != 6)
    {
        printf("1. Agregar una persona\n2. Borrar una persona.\n3. Imprimir lista ordenada por nombre.\n4. Imprimir gráfico de edades.\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
                indiceLibre = buscarLugarVacio(arrayPersonas,PERSONAS,-1);

                if(indiceLibre==-1)
                {
                    printf("NO QUEDAN LUGARES LIBRES\n");
                    break;
                }
                printf("ALTA\n");


                //asigno nombre
                printf("Ingrese el nombre:\n");
                fflush(stdin);
                scanf(" %s",auxNombre);
                //asigno edad
                printf("Ingrese edad:\n");
                fflush(stdin);
                scanf(" %d",&auxEdad);
                //asigno DNI
                printf("Ingrese DNI:\n");
                fflush(stdin);
                scanf(" %s", auxDNI);

                aux2DNI=atoi(auxDNI);

                if(buscarLugarVacio(arrayPersonas,PERSONAS,aux2DNI)!=-1)
                {
                    printf("El legajo ya existe.\n");
                    break;
                }

                arrayPersonas[indiceLibre].DNI=aux2DNI;
                strcpy(arrayPersonas[indiceLibre].nombre, auxNombre);
                arrayPersonas[indiceLibre].edad = auxEdad;

            break;

        case 2:
            printf("Ingrese DNI a dar de baja:");
            scanf("%s", auxDNI);
            resultadoBusqueda=buscarLugarVacio(arrayPersonas,PERSONAS,atoi(auxDNI));

            if(resultadoBusqueda==-1)
            {
                printf("EL DNI NO EXISTE");
                break;
            }
            arrayPersonas[resultadoBusqueda].DNI=-1;
            break;

        case 3:
            for(i=0;i<PERSONAS;i++)
            {
                if(arrayPersonas[i].DNI==-1)
                {
                    continue;
                }
                for(j=i+1;j<PERSONAS;j++)
                {
                   if(arrayPersonas[j].DNI==-1)
                   {
                       continue;
                   }
                   if(strcmp(arrayPersonas[i].nombre,arrayPersonas[j].nombre)>0)
                   {
                       auxPersona=arrayPersonas[j];
                       arrayPersonas[j]=arrayPersonas[i];
                       arrayPersonas[i]=auxPersona;
                   }
                }
            }

            break;

        case 4:
            mostrarGrafico(arrayPersonas);
            break;



        }
    }
    return 0;
}

//int i;
//int indiceLugarLibre;
//
//    struct Persona[20];
//
//
//        if(indiceLugarLibre==-1)
//        {
//
//        }

//
//    }
//    //verifico que se garde en la posicion
//    for(i=0;i<2;i++)
//    {
//        printf("%d ---> %d\n",i,Persona[i].edad);
//    }
//
//
//    return Persona[20];
//}
