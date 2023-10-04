#include "main.h"

/**
 * take_cmd - function that take a string into multiple strings
 * @linecmd: string to be taked
 * Return: token_s
 */
char **take_cmd(char *linecmd)
{
 int buffer_size = 64;
 int m = 0;
 char **token_s = malloc(buffer_size * sizeof(char *));
 char *token;

 if (!token_s)
 {
  fprintf(stderr, "allocation error in take_cmd: token_s\n");
  exit(EXIT_FAILURE);
 }
 token = strtok(linecmd, TO_DEL);
 while (token != NULL)
 {
  /* handle comments */
  if (token[0] == '#')
  {
   break;
  }
  token_s[m] = token;
  m++;
  if (m >= buffer_size)
  {
   buffer_size += buffer_size;
   token_s = realloc(token_s, buffer_size * sizeof(char *));
   if (!token_s)
   {
    fprintf(stderr, "reallocation error in take_cmd: tokens");
    exit(EXIT_FAILURE);
   }
  }
  token = strtok(NULL, TO_DEL);
 }
 token_s[m] = NULL;
 return (token_s);
}
