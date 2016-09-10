#include "misFunciones.h"

int selecOption(k)//porque obtenes un parametro?
{
    int opcion;

    printf("Seleccione una opcion:\n 1. Ingresar 1er operando (A=x).\n 2. Ingresar 2do operando (B=y). \n 3. Calcular la suma (A+B).\n 4.  Calcular la resta (A-B).\n 5. Calcular la division (A/B).\n 6. Calcular la multiplicacion (A*B).\n 7. Calcular el factorial (A!).\n 8. Calcular todas las operaciones.\n 9. Salir.\n");

    scanf("%d",&opcion);

    return opcion;

}

float functionSumar(float num1,float num2)
{
    float suma;

    suma = num1 + num2;

    return suma;
}

float functionRestar(float num1,float num2)
{
    float resta;

    resta = num1 - num2;

    return resta;
}
float functionMultiplicar(float num1,float num2)
{
    float multiplicacion;

    multiplicacion = num1 * num2;

    return multiplicacion;
}
float functionDividir(float num1,float num2)
{
    float division;

    division = num1/num2;

    return division;
}
int functionFactorial (int n1,int n2)
{
    int resp;
    int x,acum1,acum2;
    int y1,y2;
    y1 = n1;
    y2 = n2;

    acum1 = n1;
    acum2 = n2;


    printf("%d\n",y1);
    printf("%d\n",y2);

    while(y1>1)
    {
        printf("%d\n",y1);
        acum1 = acum1 * y1;
        y1--;

    }
    while(y2>0)
    {
        printf("%d\n",y2);
        acum2 = acum2 * y2;
        y2--;
    }

    return acum1;
//    return acum2;
}




//    if(n==1)
//        return 1;
//    resp = n* functionFactorial(n-1);
//    return acum;




