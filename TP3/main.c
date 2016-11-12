#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"
#define MOVIES 10

int main()
{
    Movie arrayMovies[MOVIES];

    inicializarMovie(arrayMovies,MOVIES,0);
    hardcodear(arrayMovies,MOVIES);

    int opcion = 0;
    char seguir = 's';

    while(seguir == 's')
    {
        opcion = getOpcion(opcion);
        switch(opcion)
        {
        case 1:
            if(agregarPelicula(arrayMovies,MOVIES)==1)
            {
                printf("ALTA!!!\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("ERROR!!! No se ah podido agregar la pelicula.");
            }
            break;
        case 2:
            if(borrarPelicula(arrayMovies,MOVIES)==1)
            {
                printf("BAJA!!!\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("ERROR!!! No se ah podido borrar la pelicula.");
            }
            break;
        case 3:
            if(modificarPelicula(arrayMovies,MOVIES)==1)
            {
                printf("PELICULA MODIFICADA");
                system("pause");
                system("cls");
            }
            else
            {
                printf("ERROR!!! No se ah podido modificar la pelicula.\n");
            }
            break;

        case 4:
            if(guardarArchivoBIN(arrayMovies)==1)
            {
                printf("Archivo binario creado con EXITO!!\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("ERROR!!! No se ah podido crear el archivo.\n");
            }
            break;

        case 5:
            if(generarPagina(arrayMovies,MOVIES)==1)
            {
                printf("Pagina web creada con EXITO!!!\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("ERROR!!! No se ah podido abrir la pagina web.");
            }
            break;
        case 6:
            printf("SALIR");
            seguir = 'n';
            break;

        }
    }

    return 0;
}
