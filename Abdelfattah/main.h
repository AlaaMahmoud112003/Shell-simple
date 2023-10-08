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
ssize_t no_arg(char *cmd);
void pars_cmd(char *cmd, ssize_t r, char ***av);
int my_cd(char **arcgs);
int my_env(char **arcgs);
int my_exit(char **arcgs);
int bu_path(char **av);
int env_path(char **av);
char *location(char *path, char **av);
void free_list(char ***av);


#endif
