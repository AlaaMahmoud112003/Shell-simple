#ifndef MAIN_H
#define MAIN_H

/*THE_LIBRARIES*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define TO_DEL " \t\r\n\a\""
extern char **environ;
/* function interactive and non interactive mode */
void my_no_interactive(void);
void my_interactive(void);

/* function take the command */
char **take_cmd(char *linecmd);

/* function reade command line*/
char *read_cmd(void);
char *my_read(void);

/* function execute the command */
int execute_cmd(char **arcgs);
int new_proagain(char **arcgs);

/* function built command*/
int my_cd(char **arcgs);
int my_exit(char **arcgs);
int my_env(char **arcgs);
int my_help(char **arcgs);

#endif
