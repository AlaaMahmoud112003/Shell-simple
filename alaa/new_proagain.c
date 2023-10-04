#include "main.h"

/**
 * new_proagain - function that create a new process again
 * @args: array of strings commandline and its flags
 * Return: 1 or 0.
 */
int new_proagain(char **arcgs)
{
 pid_t pidt;
 int statuscmd;

 pidt = fork();
 if (pidt ==  0)
 {
  if (execvp(arcgs[0], arcgs) == -1)
  {
   perror("error in new_proagain: in child process");
  }
  exit(EXIT_FAILURE);
 }
 else if (pidt < 0)
 {
  perror("error in new_process: fork");
 }
 else
 {
  do {
   waitpid(pidt, &statuscmd, WUNTRACED);
  } while (!WIFEXITED(statuscmd) && !WIFSIGNALED(statuscmd));
 }
 return (-1);
}
