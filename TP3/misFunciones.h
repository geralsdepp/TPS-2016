typedef struct
{
    char titulo[30];
    char genero[30];
    float duracion;
    char descripcion[100];
    float puntaje;
    int idEstado;
    int idMovie;
    char link_de_magen[500];
}Movie;

int buscarPrimerOcurrencia(Movie arrayMovies[],int cantElementos, int valor);
void estado(Movie arrayMovies[], int cantElementos,int valor);
int buscarMovies(Movie arrayMovies[],int cantElementos,char valor[]);
int modificarPelicula(Movie arrayMovies[], int cantElementos);
int agregarPelicula(Movie arrayMovies[],int cantElementos);
int borrarPelicula(Movie arrayMovies[],int cantElementos);
int generarPagina(Movie arrayMovies[], int cantElementos);
int guardarArchivoBIN(Movie arrayMovie[]);
void inicializarMovie(Movie *arrayMovies, int cant, int valor);
void hardcodear(Movie arrayMovies[],int cantElementos);

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
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
