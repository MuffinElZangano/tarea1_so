#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

// Los tres comandos simulados: printf, touch, cat (Imprimir, Crear Archivo, Leer Archivo)

// 1.- Hacer una terminal que arriba diga "University of Bio-Bio @ Administrator shell 2021"
// 2.- Hacer que la shell reciba un commando y retorne "Unknown command or wrong syntax, type 'help' for a lookup of the available commands"
// 		 a) Crear el metodo que reciba un commando
//				- En caso de no estar disponible el comando entregado retornar lo de arriba
//				- En caso de estar disponible el comando pero no tiene los parametros indicados, retornar lo de arriba
//				- En caso de que se escriba el comando 'help' entregar todos los comandos disponibles con esta sintaxis:
//						"The available comands for this shell are: "
//						"printf <message> "
//						"touch <file.format>"
//						"cat <file.format>"
// 3.- Luego de ello involucrar todo esto en un loop que acabe cuando el usuario tipee 'Salir'
// 4.- Creación de los comandos en ordén:
//     a) printf
//		 b) touch
//		 c) cat
//

//Declare functions 
bool command(char []); //Command maneja el comando invocado desde la shell, Geteamos el string obtenido en Main() y loopeamos la validez del comando.
bool separarString(char []);
void printmessage(); //Muestra en pantalla un mensaje
bool touch();
void help();
void reportMistake();

void main(){
  bool success = false;
  bool stop = false;
  char command_request[256];
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
}


void printmessage(){
  
}

bool touch(){
	
}

void help(){
	printf("\nUnknown command or wrong syntax, type 'help' for a lookup of the available commands\n");
}

bool command(char command_request[]){
	if(command_request == "printf"){
    	printmessage();
		return true;
	}
	if(command_request == "touch"){
		return true;
	}
	if(command_request == "cat"){
  		cat();
		return true;
	}
	if(command_request == "cls"){
	    system("cls");
	    return true;
	}
	if(command_request == "help"){
	    help();
	}
	return false; //Retornar Falso quiere decir que el comando es inválido, por lo tanto.
}



bool separarString(char command_request[]){
    char splitted_string_request[10][256]; 
    int i,j,ctr;
    bool success = false;
 
    j=0; 
	ctr=0;
	
    for(i=0;i<=(strlen(command_request));i++)
    {
        // Si encuentra un Espacio o NULL, asigna NULL a splitted_string_request[ctr]
         if(strcmp(command_request," ") == 0 || strcmp(command_request,"\0") == 0)
        {
            splitted_string_request[ctr][j]="\0";
            ctr++;  //+1 palabra
            j=0;    //for next word, init index to 0
        }
        else
        {
            reportMistake();
          	return false;
        }
    }
  
    success = command(splitted_string_request[0]);
          
    if(success == false){
      reportMistake();
    }
  	
    
  	return true;
}

void reportMistake(){
  printf("Unknown command or wrong syntax, type 'help' for a lookup of the available commands");
}
