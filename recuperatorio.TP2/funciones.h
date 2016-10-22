typedef struct
{
  char nombre[30];
  int edad;
  long int DNI;
  int idEstado;
  int idPersona;

}Persona;

void iniciarDatosArray(Persona arrayPersonas[], int cantElementos, int valor);
int buscarPrimerOcurrencia(Persona arrayPersonas[],int cantElementos, int valor);
void estado(Persona arrayPersonas[], int cantElementos,int valor);
int buscarIdPersonas(Persona arrayPersonas[], int cantElementos,int code);

/*************************************************************************/
int getOpcion(int opc);
int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);

void cargar(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);

/*************************************************************************/
void mostrarGrafico(Persona arrayPersonas[]);
