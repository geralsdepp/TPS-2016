#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misFunciones.h"

#define MOVIES 1000

FILE *pArchivo;

int getOpcion(int opc)
{
    char aux_op[255];
    int op;

    printf("1. Agregar pelicula\n2. Borrar pelicula.\n3. Modificar pelicula.\n4. Generar pagina web.\n5.Salir.\n");

    if(!getStringNumeros("Ingrese una opcion: \n", aux_op))
    {
        printf("Debe ingresar un  numero!!");
    }
    op = atoi(aux_op);

    return op;
}

/** \brief Busca el primer lugar no utilizado en el array.
 * \param arrayMovies es el array donde buscar.
 * \param cantElementos indica la longitud del array.
 * \return Si no hay lugares libres (-1) y si hay lugar libre (1).
 *
 */

 int buscarPrimerOcurrencia(Movie arrayMovies[],int cantElementos, int valor)
 {
     int i, auxRetorno = -1;

     for(i=0;i<cantElementos;i++) //Recorre el largo hasta
     {
         if(arrayMovies[i].idEstado==valor ) // encontrar alguna pelicula que el estado sea 0.
         {
             auxRetorno = i; // en ese caso devuelve la posicion en la que se encuentra esa pelicula dentro del array
         }
     }

     return auxRetorno;// y si no encontrase ninguno devuelve (-1)(LLENO)
 }


 /******************************************************************************************************************************************************************************************************************************/


 /** \brief inicializa mis peliculas en 0
  *
  * \param El array de peliculas
  * \param La cantidad de elementos del array.
  * \param el valor en el que los elementos seran inicializados.
  * \return -
  */

  void inicializarMovie(Movie *arrayMovies, int cant, int valor)
  {
      int i;

      for(i = 0; i < cant; i++)
      {
            arrayMovies[i].idEstado = valor;
      }
  }

  /** \brief Buscar peliculas por titulo
   *
   * \param el array de peliculas
   * \param la cantidad de lementos del array
   * \param el titulo de la pelicula a buscar
   * \return la posición de la pelicula en el array si la encuentra, si no -1
   *
   */
  int buscarMovies(Movie arrayMovies[],int cantElementos,char valor[])
    {
        int i, auxRetorno = -1;

        for(i=0;i<cantElementos;i++)
        {
            if((arrayMovies[i].idEstado==1) && (strcmp(arrayMovies[i].titulo,valor)==0))
            {
                auxRetorno = i;
            }
        }
        return auxRetorno;
    }
void hardcodear(Movie arrayMovies[],int cantElementos)
{

    char auxDescripcion[3][500]={"Rescatado de la indignante negligencia de su tía y tío, un joven con un gran destino prueba su valor mientras asistía a la Escuela Hogwarts de Brujería y Hechicería","En Londres para el funeral del Primer Ministro, Mike Banning descubre una conspiración para asesinar a todos los líderes del mundo.","Dos pacientes adolescentes de cáncer comienzan un viaje que afirma la vida para visitar a un autor recluso en Amsterdam."};
    char auxTitulo[3][50]={"Harry Potter y la piedra Filosofal","Londres bajo fuego","Bajo la misma estrella"};
    char auxLinkImagen[3][1000]={"https://images-na.ssl-images-amazon.com/images/M/MV5BNjQ3NWNlNmQtMTE5ZS00MDdmLTlkZjUtZTBlM2UxMGFiMTU3XkEyXkFqcGdeQXVyNjUwNzk3NDc@._V1_.jpg","https://images-na.ssl-images-amazon.com/images/M/MV5BMTY1ODY2MTgwM15BMl5BanBnXkFtZTgwOTY3Nzc3NzE@._V1_SY1000_CR0,0,674,1000_AL_.jpg","https://images-na.ssl-images-amazon.com/images/M/MV5BMjA4NzkxNzc5Ml5BMl5BanBnXkFtZTgwNzQ3OTMxMTE@._V1_SY1000_CR0,0,675,1000_AL_.jpg"};
    int auxDuracion[3]={230,139,206};
    int auxPuntaje[3]={10,5,7};
    int auxId[3]={1,2,3};
    char estadoAux[3] = {1,1,1};

    int i=0;

    for(i=0;i<cantElementos;i++)
    {
        strcpy(arrayMovies[i].titulo,auxTitulo[i]);
        strcpy(arrayMovies[i].descripcion,auxDescripcion[i]);
        strcpy(arrayMovies[i].link_de_magen,auxLinkImagen[i]);
        arrayMovies[i].duracion=auxDuracion[i];
        arrayMovies[i].puntaje=auxPuntaje[i];
        arrayMovies[i].idEstado=estadoAux[i];
        arrayMovies[i].idMovie=auxId[i];
    }
}
  /**
 *  @brief Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */

int agregarPelicula(Movie arrayMovies[], int cantElementos)
{
    char auxTitulo[50], auxGenero_STR[20], auxDuracion_STR[10], auxPuntaje_STR[10];
    int index, auxRetorno = 0, flag = 0;

    index = buscarPrimerOcurrencia(arrayMovies,cantElementos,0);

    if(index==-1)
    {
        printf("No hay lugares.\n");
    }
    else
    {
        while(flag==0)
        {
            printf("Ingrese titulo: ");
            fflush(stdin);
            scanf("%s",auxTitulo);
            fflush(stdin);
            flag = 1;
        }
        while(!getStringLetras("Ingrese genero: ",auxGenero_STR))
        {
            printf("El género debe contener letras!!\n");
        }
        while(!getStringNumeros("Ingrese duracion: ",auxDuracion_STR))
        {
            printf("La duracion debe contener numeros!!\n");
        }
        while(!getStringNumeros("Ingrese puntaje: ",auxPuntaje_STR))
        {
            printf("El puntaje debe contener numeros!!\n");
        }
        getString("Ingrese direccion URL: ",arrayMovies[index].link_de_magen);

        strncpy(arrayMovies[index].titulo,auxTitulo,100);
        strncpy(arrayMovies[index].genero,auxGenero_STR,100);
        arrayMovies[index].duracion = atoi(auxDuracion_STR);
        arrayMovies[index].puntaje = atoi(auxPuntaje_STR);
        arrayMovies[index].idEstado = 1;
        auxRetorno = 1;
    }

    return auxRetorno;
}


/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(Movie arrayMovies[], int cantElementos)
{
    int index, lugar_ocupado, auxRetorno = 0;
    char auxTitulo[25];


    lugar_ocupado = buscarPrimerOcurrencia(arrayMovies,cantElementos,1);
    printf("%d",lugar_ocupado);
    if(lugar_ocupado == -1)
    {
            printf("\n\nNo se encuentra el codigo\n");
    }
    else
    {
        while(!getStringLetras("Ingrese el titulo que desee borrar: ", auxTitulo))
        {
            printf("El titulo debe contener letras!!\n");
        }

        index = buscarMovies(arrayMovies,cantElementos,auxTitulo);

        if(index == -1)
        {
            printf("La pelicula no existe!!\n");
        }
        else
        {
                arrayMovies[index].idEstado=0;
                printf("\nSe elimino la pelicula: %s",arrayMovies[index].titulo);
                auxRetorno = 1;
        }
    }

    return auxRetorno;
}

/** \brief Modifca la pelicula
 *
 * \param array de peliculas
 * \param cantidad de elementos que posee el array
 * \return 1 si se realizo la tarea, 0 si no.
 *
 */
 int modificarPelicula(Movie arrayMovies[], int cantElementos)
 {
     int index, lugarOcupado, auxRetorno = 0,flag=0;
     char auxTitulo[25], auxGenero[25],auxDuracion_STR[10],auxPuntaje_STR[10];

    lugarOcupado = buscarPrimerOcurrencia(arrayMovies,cantElementos,1);

    if(lugarOcupado == -1)
    {
        printf("La pelicula no existe!!\n");
    }
    else
    {
        while(flag==0)
        {
            printf("Ingrese titulo: ");
            gets(auxTitulo);
        }
        while(!getStringLetras("Ingrese genero: ",auxGenero))
        {
            printf("El genero debe contener letras!!\n");
        }
        index=buscarMovies(arrayMovies,cantElementos,auxTitulo);
        if(index == -1)
        {
            printf("La pelicula no existe\n");
            system("pause");
            system("cls");
        }
        while(!getStringNumeros("Ingrese duración: ",auxDuracion_STR));
        {
            printf("La duracion debe contener numeros!!\n");
        }
        while(!getStringNumeros("Ingrese puntaje: ",auxPuntaje_STR))
        {
            printf("El puntaje debe contener numeros!!\n");
        }
        getString("Ingrese direccion URL (imagen): ",arrayMovies[index].link_de_magen);

        strncpy(arrayMovies[index].titulo,auxTitulo,100);
        strncpy(arrayMovies[index].genero,auxGenero,100);
        arrayMovies[index].duracion = atoi(auxDuracion_STR);
        arrayMovies[index].puntaje = atoi(auxPuntaje_STR);
        auxRetorno = 1;

    }
    return auxRetorno;
 }

  /**
 *  \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param array de peliculas
 *  @param cantidad de peliculas que hay en el array.
 * \return 1 si se realizo la tarea, 0 si no.
 */
 int generarPagina(Movie arrayMovies[],int cantElementos)
  {
        FILE* pArchivo;
        int i = 0, auxRetorno = 1;
        char buffer[2048];
        pArchivo = fopen("peliculas.html","w");

        if(pArchivo==NULL)
        {
            printf("ERROR!!! No puede abrirse el archivo!!!");
            auxRetorno = 0;
        }
        fprintf(pArchivo,"<!DOCTYPE html><html>");

               while(arrayMovies[i].idEstado==1)
                {
                        fprintf(pArchivo,"<article class='col-md-4 article-intro'>");
                        fputs("",pArchivo);
                        fprintf(pArchivo,"<a href='#'>");
                        fputs("",pArchivo);
                        fprintf(pArchivo,"<img class='img-responsive img-rounded' src='%s' alt=''>",arrayMovies[i].link_de_magen);
                        fputs("",pArchivo);
                        fprintf(pArchivo,"</a>");
                        fputs("",pArchivo);
                        fprintf(pArchivo,"<h3>");
                        fputs("",pArchivo);
                        fprintf(pArchivo,"<a href='#'>%s</a>",arrayMovies[i].titulo);
                        fputs("",pArchivo);
                        fprintf(pArchivo,"</h3>");
                        fputs("",pArchivo);
                        fprintf(pArchivo,"<ul>");
                        fputs("",pArchivo);
                        fprintf(pArchivo,"<li>Genero: %s</li>",arrayMovies[i].genero);
                        fputs("",pArchivo);
                        fprintf(pArchivo,"<li>Puntaje: %d</li>",arrayMovies[i].puntaje);
                        fputs("",pArchivo);
                        fprintf(pArchivo,"<li>Duracion: %d</li>",arrayMovies[i].duracion);
                        fputs("",pArchivo);
                        fprintf(pArchivo,"<ul>");
                        fputs("",pArchivo);
                        fprintf(pArchivo,"<li>%s</li>",arrayMovies[i].descripcion);
                        fputs("",pArchivo);
                        fprintf(pArchivo,"</article>");
                        i++;
                }

        fprintf(pArchivo,"</body></html>");
                while(!feof(pArchivo))
                {
                    cantElementos = fread(buffer,1,sizeof(buffer),pArchivo);
                    fwrite(buffer,1,cantElementos,pArchivo);
                }

           fclose(pArchivo);

        return auxRetorno;
  }

  /** \brief Genera un archivo binario
   *
   * \param array de peliculas
   * \return 1 si logro abrir y cerrar el archivo, y 0 si no.
   *
   */
   int guardarArchivoBIN(Movie arrayMovies[])
   {
       FILE* pArchivo;
       int auxRetorno = 0;

       pArchivo = fopen("bin.dat","ab+");
       if(pArchivo==NULL)
       {
           printf("Error de apertura!!\n");
       }
       else
       {
           fwrite(arrayMovies,sizeof(Movie),1,pArchivo);
           fclose(pArchivo);
           auxRetorno = 1;
       }
       return auxRetorno;
   }

/*************************************************************************/
/************************************************************************/
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[255];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
