#include <stdio.h>
#include <string.h>
#define rows 36
#define col 1000
#define alphacount 26
void print_words(char word_array[rows][col]);

int file_size(FILE *fp);

int main (int arcg, char *argv[]){
	int size;
	FILE *fp;

	/*size=file_size(fp);*/
	read_words(fp);
	return(0);

}
int file_size(FILE *fp){
	int sz = 0;
	fseek(fp,0L,SEEK_END);
	sz=ftell(fp);
	rewind(fp);
	return(sz);
}

int read_words(FILE *fp){
  int i=0, j=0,length,state=0,z,k=0;
  char character;
  char word_array[rows][col];
  (fp = fopen("test1.txt", "r"));
  char line [128];
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
    fclose(fp);
    print_words(word_array);
    alphabetical_word_count(word_array);
    return(0);
  }
  else{
    return(0);
  }
}

void print_words(char word_array[rows][col]){
  int i,j;
  for (i=0;i<36;i++){
    for (j=0;j<36;j++){
      printf("%c",word_array[i][j]);
    }
    printf("\n");
  }

}

int alphabetical_word_count(char word_array[rows][col]){
  int j=0,i,k;
  int wordcount[alphacount] = { 0 }; /*creates a 26 long letter count, with it initalized as 0*/

  for (i=0; i<26;i++){
    for (k=0;k<rows;k++){
      if ((word_array[k][0]==65+i)||(word_array[k][0]==97+i)){
	wordcount[i]=++j;
      }
    }
  j=0;
  }
  for (i=0;i<26;i++){
    printf("%d",wordcount[i]);
  }
  for (i=0;i<26;i++){
    printf("\n %c = %d ",'A'+i,wordcount[i]);
 }
  return(0);
}
/*
void print_alphabetical_word_count(wordcount[rows]){
  int i=0;
  for (i=0;i<27;i++){
    printf("%c = %d",A+i,wordcount+i);
 }






}
  */
