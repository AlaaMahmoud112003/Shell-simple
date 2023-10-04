#include "main.h"

/**
 * execute_cmd - function that if command is a builtin or a process
 * @arcgs: if is command line and its flags
 * Return: 1 or 0
 */
int execute_cmd(char **arcgs)
{
 char *built_function_list[] = {
  "cd",
  "env",
  "help",
  "exit"
 };
 int (*built_function[])(char **) = {
  &my_cd,
  &my_env, /*you can replace by your function */
  &my_help,
  &my_exit
 };
long unsigned int a = 0;

 if (arcgs[0] == NULL)
 {
  return (-1);
 }
 for (; a < sizeof(built_function_list) / sizeof(char *); a++)
 {
  if (strcmp(arcgs[0], built_function_list[a]) == 0)
  {
   return ((*built_function[a])(arcgs));
  }
 }
 return (new_proagain(arcgs));
}
