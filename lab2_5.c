#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(int argc,char* argv[]){

FILE *inStream,*outStream;


if((inStream=fopen(argv[1],"r"))!=NULL){

  if((outStream=fopen(argv[2],"w"))!=NULL){
	
	
	
	char inp;
	
	while((inp=getc(inStream))!=EOF)
	    putc(inp,outStream);
		
	fclose(outStream);
	
	struct stat rights;
        stat(argv[1],&rights);	
        chmod(argv[2],rights.st_mode);
	
  }
  else
  {
  perror("Cant write in file");
  }

fclose(inStream);



}
else
perror("Cant read file");
}
