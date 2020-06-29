#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*return non-zero if c is whitespace*/

int space_char(char c){
  return (c == '\t' || c == ' ' || c == '\n') ? 1:0;
}

/*return non-zero if c is non-whitespace*/

int non_space_char(char c){
  return (space_char(c) || c == '\0') ? 0:1;
}

/*returns a pointer to the first characted of the next space-separated word in zero-terminated
str. Return a zero pointer if str does not contain any words */

char *word_start(char *str){
  if(*str == '\0'){
    return 0;
  }
  //ignore white space
  while(space_char(*str)){
    str++;
  }

  //beginning of next word gets returned
  return str;
}

/*returns pointer to the first space char in zero-terminted str. Returns zero pointer if
  str does not contain any space char*/

char *word_end(char *str){
  //ignores non-white space
  while(non_space_char(*str)){
    str++;
  }

  //returns the sttart of the end of a word
  return str;
}

/*counts words in string passed*/

int count_words(char *str){
  int count = 0;
  //itterates while we don't reach the end or \0
  while(*str != '\0'){
    str = word_start(str);
    str = word_end(str);

    count++;
  }

  return count;
}

/*Returns a freshly allocated new zero-terminated string containing
  <len> chars from <inStr> */

char *copy_str(char *inStr, short len){
  int i;
  char *word_array;

  //allocate memory for the array to hold one word
  word_array = (char *)malloc(sizeof(char) * (len+1));

  //copy inStr to word_Array
  for(i = 0; i < len; i++){
    word_array[i] = inStr[i];
  }

  word_array[i] = '\0';

  return word_array;

}

/*returns a freshly allocated zer-terminated vector of freshly allocated space-separated 
tokens from zero-terminated str */

char **tokenize(char* str){

  //use the word count to allocate memory
  int total_words = count_words(str);

  char **myArray;

  myArray = (char**)malloc(sizeof(char*) * (++total_words));

  //populate array
  int i;
  int x = 0; //difference in length

  for(i = 0; i < total_words-1; i++){
    str = word_end(str);

    //calculate difference
    x = word_end(str)-str;

    //add new string to myArray
    myArray[i] = copy_str(str, x);

    //update pointer
    str = word_end(str);
  }

  myArray[i] = '\0';

  return myArray;
}

/*print tokens*/

void print_tokens(char **tokens){
  int i, j;
  for(i = 0; tokens[i] != NULL; i++){
    for(j = 0; tokens[i][j] != '\0'; j++){
      printf("[%c]", tokens[i][j]);
    }
    printf("\n");
  }
}

/*frees tokes and vector containing themx.*/

void free_tokens(char **tokens){
  int i;
  for(i = 0; tokens[i] != NULL; i++){
    free(tokens[i]);
  }

  free(tokens);
}

