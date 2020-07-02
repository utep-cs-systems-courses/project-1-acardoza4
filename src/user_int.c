#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

#define LEN 30

void print(char *str)
{
  while (*str != '\0') {
    printf("%c", *str);
    str++;
  }
  printf("\n\n");
}

int main()
{
  char str[LEN];
  
  List *history = init_history();

  printf("This is a tokenizer. Enter q to quit or !# to view history.\n");

  while (*str != 'q') {
    printf("$");
    fgets(str, LEN, stdin);

    if (*str != 'q' && *str != '!'){
      printf("String: %s\n", str);

      char **token = tokenize(str);

      print_tokens(token);
      free_tokens(token);

      add_history(history, str);
    }

    if (*str == '!') {
      int index = (int)(str[1] - '0');

      char *last_str = get_history(history, index);
      if (last_str != NULL) {
	printf("History at index %d:\t", index);
	print(last_str);
	
	printf("\n");
      }
    }
  }

  printf("History input:\n\n");
  print_history(history);

  free_history(history);
  printf("History cleared.\n\n");

  printf("Thanks for tokenizing!\n\n");

  return 0;
}
