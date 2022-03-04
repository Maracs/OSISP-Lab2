#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h> 
 
int walk(const char*);        
 
 char* CHECK_NAME;
 
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
    fprintf(stderr, "Not enougth parametrs\n" );
    exit(1);
    }
    
    
  
    
    CHECK_NAME=argv[2];
    exit(walk(argv[1]));
}
 

char buf[PATH_MAX];
 
int walk(const char* dirname)
{
    DIR* dp;
    struct stat st;
    struct dirent* dirp;
    int retval = 0;
 
    size_t len = strlen(dirname);
 
    if((dp = opendir(dirname)) == NULL)
    {
    perror(dirname);
    return 1;
    }
 
    strncpy(buf, dirname, len);
 
    while((dirp = readdir(dp)) != NULL)
    {
    if(strcmp(dirp->d_name, ".") == 0 ||
       strcmp(dirp->d_name, "..") == 0)
        continue;
 
    buf[len] = '/';
    buf[len+1] = '\0';
 
    strcat(buf, dirp->d_name);
    
    if(lstat(buf, &st) == -1)
    {
        perror(dirp->d_name);
        retval = 1;
        break;
    }
 
    if(S_ISDIR(st.st_mode))
    {
        
                
        if(walk(buf) == 1)
        {
        retval = 1;
        break;
        }
        
    }
    
    else 
    if(strcmp(dirp->d_name, CHECK_NAME) == 0){
    
     char  access_mod[10];   
    
     const char chars[]="rwxrwxrwx";
     for(size_t i=0;i<9;i++){
     	access_mod[i]=(st.st_mode & (1 << (8-i))) ? chars[i] :'-';
     }
     access_mod[9]='\0';
    
		   printf("%s%s\n%s%s\n%s%ld\n%s%lu\n%s%s\n","Full path:",buf,"Access options:",access_mod,"Size:",st.st_size,"Index descriptor number:",st.st_ino,"Time of creation:",ctime(&st.st_ctime));
 	     }
    buf[len] = '\0';
    }
 
    closedir(dp);
    return retval;
}
