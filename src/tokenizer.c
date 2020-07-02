#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if (c == ' ' || c == '\t' || c == '\n')
    return 1;
  else
    return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
  if (c == '\0' || space_char(c))
    return 0;
  else       
    return 1;
}            
             
/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str. Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{            
  while (space_char(*str))
    str++;   
  return str;
}            
             
/* Returns a pointer to the first space character in a
   zero-terminated str. Return a zero pointer if 
   str does not contain any space characters. */
char *word_terminator(char *str)
{            
  while (non_space_char(*str))
    str++;   
  return str;
}            
             
/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int word_num = 0;

  /* Iterate through string finding the start and end of words */
  while (*str != '\0') {    
    str = word_start(str);
    str = word_terminator(str);
    word_num++;
  }          
  return word_num;
}            
             
/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{            
  int  i;      /* Index of character. */
  char *copy;  /* Copy of original string. */
             
  copy = (char *)malloc(sizeof(char)*(len + 1));
             
  for (i = 0; i < len; i++)
    copy[i] = inStr[i];
  copy[i] = '\0';
  return copy;
}            
             
/* Prints all tokens. */
void print_tokens(char **tokens)
{            
  int i, j;  /* Indices of tokens. */
             
  for (i = 0; tokens[i] != NULL; i++){
    for (j = 0; tokens[i][j] != '\0'; j++)
      printf("%c ", tokens[i][j]);
    printf("\n");
  }         
}            
             
/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens)
{            
  int i;  /* Index of tokens. */
             
  for (i = 0; tokens[i] != NULL; i++)
    free(tokens[i]);
  free(tokens);
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/           
char** tokenize(char* str) {
  
  int word_total = count_words(str);
  
  char **array;
  array = (char **)malloc(sizeof(char*) * (word_total));

  int i;
  int diff = 0; /* The difference between start and end, used to find length */

  for (i = 0; i < word_total-1; i++) {
    str = word_start(str);
    diff = word_terminator(str) - str;
    array[i] = copy_str(str, diff);
    str = word_terminator(str);
  }

  array[i] = '\0';

  return array;
}
