#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 0
int output(int words, int lines,int WpL[]);

int main ( int argc, char *argv[] ) {
  int Lines=0;
  int switcher = 0;
  int i=0;
  int a=0;
  int Linel;
  int words=0;
  int WpL[10];  
  char input[264];
  char character;
  while (1==1){
    fgets(input,264,stdin);
    if (input[0]=='.'){
      output(words,Lines,WpL);
      return(0);
      }
    else{
      Linel=strlen(input);
      for ( i=0; i<Linel; i++ ){
	character = input[i];
    	if ( character == ' ' || character == '\n' || character == '\t' ) {
       	  switcher = 0;
      	}
	else if (switcher == 0) {
          switcher = 1;
    	  words++;
     	} 
      }
    }
    WpL[Lines]=words-a;
    a=words;
    Lines++;
  }
  return(0);
}

int output(int words, int Lines, int WpL[]){
	int i=0;
	printf("There are %d words and %d lines.\n",words,Lines);
	for (i=0;i<Lines;i++){
		printf("There are %d words in line %d.\n",WpL[i],i+1);
	}
	return(0);
	}
