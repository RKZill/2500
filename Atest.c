#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define rows 36
#define col 1000
#define alphacount 26
void print_words(char** word_array, FILE *fp);
char** read_words(FILE *fp);
int file_size(FILE *fp);
int alphabetical_word_count(char** word_array, FILE *fp);

int main (int arcg, char *argv[]){
	int size,COLS,ROWS=45,i,j;
	char** word_array;
	FILE *fp;
	fp = fopen("test1.txt", "r");

	word_array = read_words(fp);
	print_words(word_array, fp);

	alphabetical_word_count(word_array, fp);

	fclose(fp);

	return(0);
}
int file_size(FILE *fp){
	int sz = 0;
	fseek(fp,0L,SEEK_END);
	sz=ftell(fp);
	rewind(fp);
	return(sz);
}

char **read_words(FILE *fp){
  int i=0, j=0,state=0,k=0;
  int e,length,z;
  char character;
  int ROWS,COLS;
  char **word_array;
  char line [128];

  COLS=file_size(fp);
  word_array = malloc(sizeof(char*) * COLS);
  for (e=0;e<COLS;e++){
	word_array[e] = malloc(sizeof(char) * 45);
  }
  /*strcpy(word_array[i], line);*/
  if ( fp != NULL){
    while (fgets (line, 500, fp)!=NULL){
      length = strlen(line);
      for ( i=0; i<length; i++ ){
	character = line[i];
    	if (character==' '||character == '\n'||character == '\t'||character == '\0') {
	  j++;
	  k=0;
	}
	else{
	  word_array[j][k]=line[i];
	  k++;
	}
      }
    }
    /*word_array[counter][0]='\0';
    print_words(word_array);*/

    return word_array;
  }
  else{
    return(0);
  }
}

void print_words(char **word_array, FILE *fp){
	int ROWS=45,COLS,i,j;
	COLS=file_size(fp);
	for (i=0;i<COLS;i++){
          for (j=0;j<ROWS;j++){
          printf("%c",word_array[i][j]);
          }
					if (strcmp(word_array[i], "\0") != 0) {
						printf("\n");
					}
        }
}

int alphabetical_word_count(char** word_array,FILE *fp){
  int j = 0, i = 0,k = 0;
  int wordcount[alphacount] = {0}; /*creates a 26 long letter count, with it initalized as 0*/
  int COLS=file_size(fp);
	for (i=0; i<26;i++){
    for (k=0;k<COLS;k++){
      if ((word_array[k][0]==65+i)||(word_array[k][0]==97+i)){
	wordcount[i] = ++j;
      }
    }
  j=0;
  }

  for (i=0;i<26;i++){
    printf("\n %c = %d ",'A'+i,wordcount[i]);
 }
  return(0);
}
