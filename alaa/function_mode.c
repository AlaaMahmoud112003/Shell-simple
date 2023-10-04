#include "main.h"

/**
 * my_interactive - function that to go the interactive mode.
 * Return: void
 */
void my_interactive(void)
{
char *linecmd;
char **arcgs;
int statusmode = -1;

do {
 printf("my simple shell$ ");
 linecmd = read_cmd();
 arcgs = take_cmd(linecmd);
 statusmode = execute_cmd(arcgs);
 free(linecmd);
 free(arcgs);
/*to exit with status mode*/
 if (statusmode >= 0)
  {
   exit(statusmode);
  }
 } while (statusmode == -1);
}

#include "main.h"

/**
 * my_no_interactive - function that to go the non interactive mode.
 * Return: it is void
 */
void my_no_interactive(void)
{
char *linecmd;
char **arcgs;
int statusmode = -1;

do {
 linecmd = read_cmd();
 arcgs = take_cmd(linecmd);
 statusmode = execute_cmd(arcgs);
 free(linecmd);
 free(arcgs);
/* to exit with status mode */
 if (statusmode >= 0)
  {
   exit(statusmode);
  }
 } while (statusmode == -1);
}
