typedef struct
{
  char nombre[30];
  int edad;
  int DNI;

}Persona;

void cargarPersonas(Persona arrayPersonas[],int cantElement,int valor);
int buscarLugarVacio(Persona arrayPersonas[],int cantElement,int valor);

/*************************************************************************/
