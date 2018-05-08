//Nome: Eduardo Airton
//GitHub: https://github.com/EduardoAirton
//Linkedin: https://www.linkedin.com/in/eduardo-airton/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//directive to work with Mac/Linux and Windows without have to change the code
#ifdef WINDOWS
	#define BUFFER fflush(stdin);
	#define CLEAN system("cls");
	#define PAUSE getch();
#else
	#define BUFFER fpurge(stdin);
	#define CLEAN system("clear");
	#define PAUSE getchar();
#endif

//Prototypes
void readInt(char *msg, int *value);
void readValidateInt(char *msg, char *errorMsg, int minValue, int maxValue, int *value);
void readFloat(char *msg, float *value);
void readValidateFloat(char *msg, char *errorMsg, float minValue ,float maxValue, float *value);
void readValidateText(char *msg, char *errorMsg, char *text, int size);
char readValidateChar(char *msg, char *opc);
void readValidateOption(char *msg, char *errorMsg, char *validOptions, char *option);
void removeRegister(char *text);
FILE *openFile(char *fileName, char *openingMode)
void readFile()
int checkFile(char *fileName)

int main(int argc, char const *argv[]) {
	//Put your code here
}

// Objective: Read a int
// parameters: String memory address
void readInt(char *msg, int *value) {
	int ret;
	do{
		printf("%s", msg);
		BUFFER
		ret = scanf("%d", value);
		BUFFER

		if(ret == 0){
			printf("error occurred while trying to read the number.\n");
			break;
		}
	}while(ret == 0);
}

// Objective: Read and validate a int
// parameters: String Memory address, message and error message, Min and Max value of the int
void readValidateInt(char *msg, char *errorMsg, int minValue, int maxValue, int *value){
	do{
		readInt(msg, value);
		BUFFER
		if(*value < minValue || *value > maxValue)
		{
			printf("%s", errorMsg);
			CLEAN
		}
	}while(*value < minValue || *value > maxValue);
}

// Objective: Read a float number
// parameters: Message Address
void readFloat(char *msg, float *value){
	int ret = 0;
	do{
		printf("%s", msg);
		BUFFER
		ret = scanf("%f", value);
		BUFFER

		if(ret == 0){
			printf("error occurred while trying to read the number.\n");
			caracter
			CLEAN
		}

	}while(ret == 0);
}

// Objective: Read and validate a float number
// parameters: Msg address, error Msg address, min and max value of the flat
void readValidateFloat(char *msg, char *errorMsg, float minValue ,float maxValue, float *value){
	do{
		readFloat(msg, value);
		if(*value < minValue || *value > maxValue){
			printf("%s", errorMsg);
			caracter
			CLEAN
		}
	}while(*value < minValue || *value > maxValue);
}

// Objective: Read and validate a String
// parameters: Mensage and error mensage memory address, the String and the size of that String
void readValidateText(char *msg, char *errorMsg, char *text, int size) {
	do{
		printf("%s", msg);
		BUFFER
		fgets(text, size, stdin);
		BUFFER
		removeRegister(text);
		CLEAN

		if(strlen(text) ==0){
			printf("%s", errorMsg);
			caracter
			CLEAN
		}
	}while(strlen(text) == 0);
}

// Objective: Validate a char
// parameters: Mensage and option memory address
// Returns: The answer
char readValidateChar(char *msg, char *opc){
	int flag=0;
	char resp;
	do{
		printf("%s",msg);
		BUFFER
		resp = toupper(getchar());
		if (strchr(opc, resp) != NULL){
			flag=1;
		}
	}while(flag==0);

	return resp;
}

// Objective: Read a option
// parameters: Mensage and error mensage memory address, valid options
void readValidateOption(char *msg, char *errorMsg, char *validOptions, char *option) {

    do {
		printf("%s",msg);
		BUFFER
	  *option = toupper(getchar());
		BUFFER

		if(strchr(validOptions, *option) == NULL) {
			printf("%s",errorMsg);
		}

	} while(strchr(validOptions, *option) == NULL);
}

// Objective: Remove the \n in the String that change to the next line
// parameters: Mensage memory address
void removeRegister(char *text) {
	if(text[strlen(text)-1] == '\n') {
		text[strlen(text)-1] = '\0';
	}
}

//---------------------------------------------FILE------------------------------------
//"r"	Open for reading. If the file does not exist, fopen() returns NULL.
//"rb"	Open for reading in binary mode. If the file does not exist, fopen() returns NULL.
//"w"	Open for writing.	If the file exists, its contents are overwritten. If the file does not exist, it will be created.
//"wb"	Open for writing in binary mode. If the file exists, its contents are overwritten. If the file does not exist, it will be created.
//"r+"	Open for both reading and writing.	If the file does not exist, fopen() returns NULL.
//"rb+"	Open for both reading and writing in binary mode.	If the file does not exist, fopen() returns NULL.
//-------------------------------------------------------------------------------------

//Objective: Open a file
//parameters: File name memory address, mode
//Returns: A file
FILE *openFile(char *fileName, char *openingMode) {
	FILE *arq;

	arq = fopen(fileName, openingMode);
	if(arq != NULL) {
		printf("File successfully opened!\n");
		CLEAN
	}
	return arq;
}

// Objective: Abrir o arquivo de farmacia
// parameters: nenhum
void readFile(){
Class class;
	FILE *arq;
	arq = openFile("FileName.txt","Mode");
	CLEAN
	if(arq != NULL){
	if(fread(&class,sizeof(class),1,arq) == 1){
		printf("Name: %.30s\n", class.name);
		printf("Address: %s,%s-%s\n",class.address,class.city,class.state);
	}
}
	fclose(arq);
}

// Objective: Check if the file exist
// parameters: File name address
// Returns: 1 if doesn't exist and 0 if exist
int checkFile(char *fileName){
	int flag;
	FILE *arq;
	arq = fopen(fileName, "r");
	if(arq == NULL){
		flag = 1;
	}else{
		flag = 0;
	}
	fclose(arq);
	return flag;
}
