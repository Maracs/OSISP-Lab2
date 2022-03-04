#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc,char* argv[]){

char cwd[256];
struct dirent *entry;
DIR *dp;

printf("%s\n","Current directory:");
if((dp=opendir(getcwd(cwd,sizeof(cwd))))==NULL)
	perror("opendir() error");
else{

	while((entry=readdir(dp))!=NULL)
		     printf(" %s\n", entry->d_name);
	closedir(dp);
}

printf("%s\n","Root directory:");
if((dp=opendir("/"))==NULL)
	perror("opendir() error");
else{

	while((entry=readdir(dp))!=NULL)
		     printf(" %s\n", entry->d_name);
	closedir(dp);
}




}
