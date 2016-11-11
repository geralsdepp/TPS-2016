#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"

int getOpcion(int opc)
{
    char aux_op[255];
    int op;

    printf("1. Agregar una persona\n2. Borrar una persona.\n3. Imprimir lista ordenada por nombre.\n4. Imprimir gráfico de edades.\n5.Salir.\n");

    if(!getStringNumeros("Ingrese una opcion: \n", aux_op))
    {
        printf("Debe ingresar un  numero!!");
    }
    op = atoi(aux_op);

    return op;
}

void iniciarDatosArray(Persona arrayPersonas[], int cantElementos,int valor)
{
    int i;

    for(i=0;i<cantElementos;i++)
    {
        arrayPersonas[i].idEstado = valor;
    }
}

/** \brief Busca el primer lugar no utilizado en el array.
 * \param arrayPersonas es el array donde buscar.
 * \param cantElementos indica la longitud del array.
 * \return Si no hay lugares libres (-1) y si hay lugar libre (1).
 *
 */

 int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantElementos, int valor)
 {
     int i;

     for(i=0;i<cantElementos;i++) //Recorre el largo hasta
     {
         if((arrayPersonas[i].idEstado == 0 || arrayPersonas[i].idEstado == -1)&& valor == -1 ) // encontrar alguna pelicula que el estado sea 0.
         {
             return i; // en ese caso devuelve la posicion en la que se encuentra esa pelicula dentro del array
         }
         else
         {
             if(valor == arrayPersonas[i].idPersona && arrayPersonas[i].idEstado == 1)
             {
                 return i;
             }
         }
     }

     return -1;// y si no encontrase ninguno devuelve (-1)(LLENO)
 }

 /** \brief Busca iD de personas
  *
  * \param array de personas
  * \param cantidad de elementos que contiene el array.
  * \param id a ser encontrado
  * \return me devuelve el id encontrado y si no -1
  *
  */
  int buscarIdPersonas(Persona arrayPersonas[], int cantElementos,int id)
  {
      int i;
      for(i=0; i<cantElementos; i++)
      {
          if(arrayPersonas[i].idPersona == id && arrayPersonas[i].idEstado == 1)
          {
              return i;
          }
      }
      return -1;
  }
  //int ordenarAlfab()

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
    fflush(stdin);
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
    fflush(stdin);
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

// * \brief Genera un número aleatorio
// * \param desde Número aleatorio mínimo
// * \param hasta Número aleatorio máximo
// * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
// * \return retorna el número aleatorio generado
// *
// */
//char getNumeroAleatorio(int desde , int hasta, int iniciar)
//{
//    if(iniciar)
//        rand (time(NULL));
//    return desde + (rand() % (hasta + 1 - desde)) ;
//}


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
    fflush(stdin);
    scanf ("%s",input);
    fflush(stdin);
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


void contarEdades(Persona arrayPersonas[],int cantElementos, int* menor18, int* de18a35, int* mayor35)
{
    int i;

    for(i=0; i<cantElementos;i++)
    {
        if(arrayPersonas[i].idEstado==1 && arrayPersonas[i].edad<18)
        {
            *menor18 = *menor18 + 1;
        }
        else if(arrayPersonas[i].idEstado==1 && arrayPersonas[i].edad>35)
        {
            *mayor35 = *mayor35 + 1;
        }
        else if(arrayPersonas[i].idEstado==1 && arrayPersonas[i].edad>=18 && arrayPersonas[i].edad<=35)
        {
            *de18a35 = *de18a35 + 1;
        }
    }

}
 void mostrarGrafico(int cantMenor18, int cant18a35, int cantMayor35)
{
    int aux = 0;
    int i = 0;
    int flag = 0;

    if(cantMenor18>=cantMayor35 && cantMenor18>=cant18a35)
    {
        aux = cantMenor18;
    }
    else if(cantMayor35>=cantMenor18 && cantMayor35>=cant18a35)
    {
        aux = cantMayor35;
    }
    else if(cant18a35>=cantMenor18 && cant18a35>=cantMayor35)
    {
        aux = cant18a35;
    }
    for(i=aux;i>0;i--)
    {
        printf("%d |",i);

        if(i<= cantMenor18)
        {
            printf("*");
        }
        if(i<= cant18a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= cantMayor35)
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
    printf("\n  |<18\t18-35\t>35");
    printf("\n   %d\t%d\t%d", cantMenor18, cant18a35, cantMayor35);

}
void ordenarNombres(Persona arrayPersonas[],int cantElementos)
{
    int i,j;
    Persona aux_personas;
    for(i=0; i < cantElementos; i++)
    {
        if(arrayPersonas[i].idEstado==1)
        {
            for(j = i +1 ; j < cantElementos; j++)
            {
                if(arrayPersonas[j].idEstado==1)
                {
                    if(strcmp(arrayPersonas[i].nombre,arrayPersonas[j].nombre) > 0)
                    {
                        aux_personas = arrayPersonas[i];
                        arrayPersonas[i] = arrayPersonas[j];
                        arrayPersonas[j] = aux_personas;
                    }
                }

            }
        }

    }
}
