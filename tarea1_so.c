#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#define array_length(x)  (sizeof(x) / sizeof((x)[0]))

// Los tres comandos simulados: printf, touch, cat (Imprimir, Crear Archivo, Leer Archivo)

// 1.- Hacer una terminal que arriba diga "University of Bio-Bio @ Administrator shell 2022"
// 2.- Hacer que la shell reciba un commando y retorne "Unknown command or wrong syntax, type 'help' for a lookup of the available commands"
// 		 a) Crear el metodo que reciba un commando
//				- En caso de no estar disponible el comando entregado retornar lo de arriba
//				- En caso de estar disponible el comando pero no tiene los parametros indicados, retornar lo de arriba
//				- En caso de que se escriba el comando 'help' entregar todos los comandos disponibles con esta sintaxis:
//						"The available comands for this shell are: "
//						"printf <message> "
//						"touch <file.format>"
//						"cls"
//						"ls"
// 3.- Luego de ello involucrar todo esto en un loop que acabe cuando el usuario tipee 'Salir'
// 4.- Creación de los comandos en ordén:
//       a) printf
//		 b) touch
//		 c) cls
//		 d) ls
//


//Declare functions
bool command(char [], char []); //Command maneja el comando invocado desde la shell, Geteamos el string obtenido en Main() y loopeamos la validez del comando.
bool separarString(char []);
void printMessage(char []); //Muestra en pantalla un mensaje
bool touch(char []);
void help();
void delay();
void reportMistake();
char filelist[256][256];

int main(){
    bool success = false;
    bool stop = false;
    char command_request[256];
    system("cls");
    printf("University of Bio-Bio @ Administrator shell 2022\n");
    do{
        printf("epereira@loki:~$ ");
        gets(command_request); //Recibe input de string comenzando con " " o con ' '
        if(strcmp(command_request,"Salir") == 0 || strcmp(command_request,"salir") == 0){
            stop = true;
        } else {
            if(strlen(command_request) == 0){
                reportMistake();
            } else {
                success = separarString(command_request);

            }
        }

    } while(stop == false);

    printf("Shutting down connection");
    delay(1000);
    system("cls");
    printf("University of Bio-Bio @ Administrator shell 2022\n");
    printf("Shutting down connection.");
    delay(1000);
    system("cls");
    printf("University of Bio-Bio @ Administrator shell 2022\n");
    printf("Shutting down connection..");
    delay(1000);
    system("cls");
    printf("University of Bio-Bio @ Administrator shell 2022\n");
    printf("Shutting down connection...");
    delay(1000);

    return 0;
}


void printMessage(char suffix[]){
	printf("\033[0;32m"); //Set color to green
	printf("%s\n",suffix);
	printf("\033[0;37m"); //Set color to white
}

void ls(){
  printf("\033[0;34m"); //Set color to blue
  	int i = 0;
  	int size = array_length(filelist);
  	do{
  		printf("%s\n",filelist[i]);
  		i++;
	  }while(filelist[i][0]);
  printf("\033[0;37m"); //Set color to white
}

bool touch(char suffix[]){
	//Escribir un 'archivo' en la estructura de datos para luego poder imprimir la estructura de datos con LS.
  bool start_j = true;
  int i = 0, j = 0;
  int size = array_length(filelist);
  do{
    i++;
  }while(filelist[i][0]);
  
	for(j=0;start_j==true;j++){
		filelist[i][j] = suffix[j];
		if(suffix[j+1] == '\0' || !suffix[j+1]){
		  start_j = false;
		}
	}
	return false;
}
void help(){
    printf("\nWelcome to Marcos and Ben's simulated Linux Shell, these are the available commands:\n");
    printf("	1. print <message> //Prints out a message on the screen. printf \"text\"\n");
    printf("	2. touch <file_name.format> //Creates a file with the designated file name and format. touch \"file.format\"\n");
    printf("	3. ls						//Shows the files available.\n");
    printf("NOTE: Every oommand that uses suffix should be double quoted.\n");
}


bool command(char command_request[], char suffix[]){
    if(strcmp(command_request,"print ") == 0){
        printMessage(suffix);
        return true;
    }
    if(strcmp(command_request,"touch ") == 0){
        touch(suffix);
        return true;
    }
    if(strcmp(command_request,"cls") == 0){
        system("cls");
        return true;
    }
    if(strcmp(command_request,"help") == 0){
        help();
        return true;
    }
    if(strcmp(command_request,"ls") == 0){
        ls();
        return true;
    }
    
    reportMistake();
    return false; //Retornar Falso quiere decir que el comando es inválido, por lo tanto.
}

bool separarString (char command_request[]){
	   char comando[128];
	   char suffix[256];
	   int i = 0, j = 0;
  	 bool is_suffix = false, continue_splitting = true;
  
  
	for(i=0;continue_splitting == true;i++){
		
      if(is_suffix == false){
      	
      	comando[i] = command_request[i];
      	
		if(comando[i] == ' '){
			
          if(command_request[i + 1] == '"'){
          	
            is_suffix = true;
            i = i+1;
            
          } else {
          	
            continue_splitting = false;
            
          }
		} else {
			
          if(comando[i] == '\0'){
          	
            continue_splitting = false;
            
          } else {
          	

		  }
          
        }
        
      } else {
        suffix[j] = command_request[i];
        j++;
		if(command_request[i + 1] == '"'){
			continue_splitting = false;
		}
      }
	}
		
	command(comando, suffix);
  return true;
}


void reportMistake(){
    printf("Unknown command or wrong syntax, type 'help' for a lookup of the available commands\n");
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
