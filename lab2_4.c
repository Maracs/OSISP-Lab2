#include <stdio.h>

int ArrayOfCharToInt(char* inp){

int result=0, i=0;

while(inp[i]!='\0'){
result=result*10+(inp[i]-'0');
i++;
}

return result;
}

int main(int argc,char* argv[]){

FILE* stream;
int N=ArrayOfCharToInt(argv[2]),i=0;
char inp;


if((stream=fopen(argv[1],"r"))!=NULL){


	while((inp=fgetc(stream))!=EOF){
	
		if(N!=0 && i%N==0 && i!=0){
			getc(stdin);
		}
			putc(inp,stdout);
			i++;
			
}
fclose(stream);
}
else
perror("Cant read file");
}
