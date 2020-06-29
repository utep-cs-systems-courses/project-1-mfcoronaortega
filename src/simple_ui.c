#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

#define MAX 50

//print character array
void print(char *str){
  while(*str != '\0'){
    printf("%c", *str);
    str++;
  }
  printf("\n\n");
}

/*Simple UI*/

int main(){
  //array for ln 50
  char str[MAX];

  //linked list
  //List *history = init_history();

  printf("Initiating Tokenizer =-) (enter 'x' to exit)\n");

  //continued to receive input unless str = x
  while(*str != 'x'){
    printf(">");
    fgets(str, MAX, stdin);

    if(*str != 'x' && *str != '!'){
      printf("> %s\n", str);

      //tokenizing input
      char **token = tokenize(str);

      printf("Tokenized String:\n");

      print_tokens(token);
      free_tokens(token);

      //update history
      // add_history(history, str);
    }
    //if(*str == '!'){
    //int i = (int)(str[1] - '0');
    //char *prev_str = get_history(history, i);
    //if(prev_str != NULL){
    //	printf("The History item is:\t");
    //	print(prev_str);
    //	printf("\n");
    //}
    //}
  }
  printf("Your input history is:\n");
  //print_history(history);

  //free linked list
  //free_history(history);
  //printf("History Cleared");
  printf("Exiting System");
  return 0;
}
