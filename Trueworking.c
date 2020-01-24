#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define rows 36
#define col 1000
#define alphacount 26
void print_words(char** word_array);
char** read_words(FILE *fp);
int file_size(FILE *fp);
int* alphabetical_word_count(char** word_array);
void print_alphabetical_word_count(int* alpha_count_array);
char*** create_alphabetical_array(char** word_array, int* alpha_count_array);
void free_alphabetical_array(char*** alphabetical_array);
void fprint(char*** alphabetical_array, int*alpha_count_array);

int main (int arcg, char *argv[]){
	int COLS,ROWS=45,i=0;
	char** word_array;
	char*** alphabetical_array;
	int* alpha_count_array;
	FILE *fp;
	fp = fopen("test1.txt", "r");/*opens file in main so it doesnt have to be opened and closed in each function that uses it*/
          /*COLS is defined in main as well so any functions tht use the length of the array dont have to retrive file size by itself*/
	word_array = read_words(fp);
	print_words(word_array);

	alpha_count_array = alphabetical_word_count(word_array);

  print_alphabetical_word_count(alpha_count_array);

	alphabetical_array = create_alphabetical_array(word_array,alpha_count_array);

	fprint(alphabetical_array,alpha_count_array);

	free_alphabetical_array(alphabetical_array);
	fclose(fp);

	while(word_array[i]!=NULL){
	free(word_array[i]);
	i++;
	}
  free(word_array);
	free(alpha_count_array);

	return(0);
}
int file_size(FILE *fp){
	int sz = 0;
	fseek(fp,0L,SEEK_END);
	sz=ftell(fp);
	printf("%d\n", sz);
	rewind(fp);
	return(sz);
}

char **read_words(FILE *fp){
  int i=0, j=0,state=0,k=0;
  int e,length,z;
  int cols;
  char **word_array;
  char line [128];
  cols=file_size(fp);
  word_array = malloc(sizeof(char*) * cols);
  for (e=0;e<cols;e++){
		word_array[e] = malloc(sizeof(char) * 46);
  }
  /*strcpy(word_array[i], line);*/
  if ( fp != NULL){
    while (fgets (line, 500, fp)!=NULL){
      length = strlen(line);
      for ( i=0; i<length; i++ ){
    	if (line[i]==' '||line[i] == '\n'||line[i] == '\t'||line[i] == '\0') {
	  j++;
	  k=0;
	}
	else{
	  word_array[j][k]=line[i];
	  k++;
	}
  }
    }
	 word_array[j]=NULL;
    return word_array;
  }
  else{

  }
}

void print_words(char **word_array){
	int ROWS=46,i,j;
	while(1==1){
		if ((word_array[i]==NULL)){
				return;
			}
          for (j=0;j<ROWS;j++){
          printf("%c",word_array[i][j]);
          }
					if (strcmp(word_array[i], "\0") != 0) {
						printf("\n");
					}
		i++;
    }
}

int* alphabetical_word_count(char** word_array){
  int j = 0, i = 0,k = 0;
	int *alpha_count_array;
	alpha_count_array = malloc(sizeof(int) * 26); /*creates a 26 long letter count as an int array*/
	for (i=0; i<26;i++){						/*i is a counter which will go through ever letter in ascii*/
    while (1==1){
			if (word_array[k] == NULL){
				k=0;
				break;
			}
					/*j is for going through every word in the file as COLS is filesize*/
      if ((word_array[k][0]==65+i)||(word_array[k][0]==97+i)){
				/*ascii for A and a, plus 26 (i) from the above loop, so checks for A-Z&a-z*/
	    alpha_count_array[i] = ++j;         /*stored into an array which will be returned*/
      }
			k++;
    }
  j=0;
	}                       /*resets what the next words count will be*/
  return(alpha_count_array);
}

void print_alphabetical_word_count(int* alpha_count_array){
	int i;
	for (i=0;i<26;i++){
		printf(" %c = %d ,",'A'+i,alpha_count_array[i]);
		if (i==8||i==17){
			printf("\n");
		}
  }
}


char*** create_alphabetical_array(char** word_array, int* alpha_count_array){
  char*** alphabetical_array;
	int max_word_length;
  int i,j,l,z=0,k=0,x;
	int max_words;
	int counter_array[27];
	for (i=0;i<26;i++){  /*Copying alpha count array into counter array which is used to count*/
		counter_array[i]=alpha_count_array[i];
	}
	for(i=0;i<26;i++){ /*This finds the highest number of words in an array which is used to malloc every letter that amount of words*/
		if (counter_array[0] < counter_array[i]){
			counter_array[0] = counter_array[i];
		}
	}

	max_word_length=counter_array[0];
 /*Initalized variable with readable name, max_word_length*/
  alphabetical_array = malloc(sizeof(char*)*27);
	for (i=0;i<27;i++){
		alphabetical_array[i] = malloc(sizeof(char*)*max_word_length);
		for (j=0;j<max_word_length;j++){
			alphabetical_array[i][j] = malloc(sizeof(char*)*45);
		}
	}
/*	Here, i use my maxwordnum integer as the array length, i assume in a text document most of the letters will be of similiar count so no need for a jagged array*/
while (1==1){
	if (word_array[k]==NULL){
		break;
	}
	k++;
}


/*^^This is my word count from before */
for (i=0;i<26;i++){
	j=0;
		for (l=0;l<k;l++){
			if ((word_array[l][0]==65+i)||(word_array[l][0]==97+i)){
				strcpy(alphabetical_array[i][j],word_array[l]);
				j++;
			}
		}
	}

                     /*resets what the next words count will be*/
	/*
	for (i=0;i<27;i++){
		for(j=0;j<max_word_length;j++){
			free(alphabetical_array[i][j]); /*The first part of the 3d array is 26 for each array of arrays for each letter
		}
	}
printf("free");
return(0);
*/

return(alphabetical_array);
}

void free_alphabetical_array(char*** alphabetical_array){
	int i=0,x=0;
	/*
	while (strcmp(alphabetical_array[i][x],"\0")!=0){
		free(alphabetical_array[i][x]);
		i++;
		while (alphabetical_array[x]!=NULL){
			free(alphabetical_array[x]);
			x++;
		}
	}*/
	free(alphabetical_array);
}

void fprint(char*** alphabetical_array, int* alpha_count_array){
	int a,i,letter_count=-1;
	for (a=0;a<26;a++){
		letter_count++;
		printf("\n'%c'\n",65+a);
		if (alpha_count_array[a]=='\0'){
			printf("There are no words that start with the letter %c\n",letter_count+65);
		}
		else {
			for (i=0;i<alpha_count_array[a];i++){
				printf("%s \n",alphabetical_array[a][i]);
			}
		}
	}
	printf("\n");
}
