#include <stdio.h>
#include <stdlib.h>
#include "misFunciones.h"

/*Calculadora con las 4 funciones básicas*/

int main()
{
    int menuOpcion;
    int opcion;
    char seguir ='s';
    float primerOperando;
    float segundoOperando;
    int op1=0;//bandera del operando 1.
    int op2=0;//bandera del operando 2.
    float sumaNumeros;
    float restarNumeros;
    float multiplicacionNumeros;
    float divisionNumeros;
    float teclado;
    int Factorial;
    int factorialUno;
    int factorialDos;
    int num;
    float calcularOperaciones;
    float resultado;


    while(seguir=='s')
    {

        menuOpcion = selecOption(menuOpcion);

        system("cls");

        switch(menuOpcion)
        {
        case 1:
            system("cls");
            printf("Ingrese primer operando: \n");
            scanf("%f", &primerOperando);
            printf("Primer operando: %f \n",primerOperando);


            printf("Desea seguir?: \n");
            scanf("%s", &seguir); /* no le gusta esta linea
                                     por alguna razon me lo toma como string
                                    y habia que usar la mascara de string %sokjaja*/

            op1 = 1;



        case 2:

            system("cls");
            printf("Ingrese segundo operando: \n");
            scanf("%f", &segundoOperando);

            printf("Primer operando: %f \n",segundoOperando);

            printf("Desea seguir?: \n");
            scanf("%s", &seguir);

            op2 = 1;
            break;



        case 3:

            system("cls");
            if(op1==1 && op2==1)
            {
                sumaNumeros = functionSumar(primerOperando,segundoOperando);
                printf("La suma es: %f \n",sumaNumeros);

                printf("Desea seguir?: \n");
                scanf("%s",&seguir);


            }
            else
            {
                if(op1==0 || op2==0)
                {
                    printf("ERROR!!! no se ha ingresado el operando \n");
                }
            }
            break;

        case 4:

            system("cls");
            if(op1==1&&op2==1)
            {
                restarNumeros = functionRestar(primerOperando,segundoOperando);

                printf("La resta es: %f \n",restarNumeros);

                printf("Desea seguir?: \n");
                scanf("%s",&seguir);


            }
            else
            {
                if(op1==0 || op2==0)
                {
                    printf("ERROR!!! No se ha ingresando el operando \n");
                }
            }
            break;

        case 5:

            system("cls");
            if(op1==1&&op2==1)
            {

                if(segundoOperando==0)
                {
                    printf("No valido");
                    break;
                }
                else
                {
                    divisionNumeros = functionDividir(primerOperando,segundoOperando);

                    printf("La division es: %f\n",divisionNumeros);

                    printf("Desea seguir?:\n");
                    scanf("%s",&seguir);
                }

            }

            else
            {
                if(op1=0||op2==0)
                {
                   printf("ERROR!!! No se ah ingresado el operando\n");
                }
            }
            break;

        case 6:

            system("cls");
            if(op1==1&&op2==1)
            {
                multiplicacionNumeros = functionMultiplicar(primerOperando,segundoOperando);

                printf("La multiplicacion es: %f",multiplicacionNumeros);

                printf("Desea seguir?:");
                scanf("%s",&seguir);
            }
            else
            {
                    if(op1==0 || op2==0)
                    {
                        printf("ERROR!!! No se ha ingresado el operando \n");
                    }
            }
            break;


        case 7:

            system("cls");

            printf("Ingrese un numero para calcular el factorial:\n");
            scanf("%d",&primerOperando);
            system("cls");
            printf("Ingrese un segundo numero para calcular el factorial:\n");
            scanf("%d",&segundoOperando);
            system("cls");
            Factorial=functionFactorial(primerOperando,segundoOperando);//Llamo a la funcion

            printf("El factorial de %d es %d \n",primerOperando,factorialUno);
            printf("El factorial de %d es %d \n",segundoOperando,factorialDos);

            break;

        case 8:
            system("cls");
            resultado=functionSumar(primerOperando,segundoOperando);
            printf("La suma es: %f\n",resultado);
            resultado=functionRestar(primerOperando,segundoOperando);
            printf("La resta es: %f\n",resultado);
            resultado=functionMultiplicar(primerOperando,segundoOperando);
            printf("La multiplicacion es: %f\n",resultado);
            resultado=functionDividir(primerOperando,segundoOperando);
            printf("La division es: %f\n",resultado);

            resultado=functionFactorial(primerOperando,segundoOperando);
            printf("El factorial de %d es %d\n",primerOperando,resultado);

            resultado=functionFactorial(segundoOperando,primerOperando);
            printf("El factorial de %d es %d\n",segundoOperando,resultado);

            break;

        case 9:

            system("cls");
            seguir = "n";
            break;

        }
    }

    //
    return;

}
