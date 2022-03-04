#include <stdio.h>

int main(int argc,char* argv[]){
FILE *stream;
char inp;
if((stream=fopen(argv[1],"w"))!=NULL){
while((inp=getc(stdin))!='`')
{
putc(inp,stream);
}


fclose(stream);

}
else
perror("Error opening myfile");

}
