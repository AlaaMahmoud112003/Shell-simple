#ifndef MAIN_H
#define MAIN_H

/*THE_LIBRARIES*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
extern char **environ;
#define TO_DEL " \t\r\n\a\""

ssize_t no_arg(char *cmd);
void pars_cmd(char *cmd, ssize_t r, char ***av);
int my_cd(char **arcgs);
int my_env(char **arcgs);
int my_exit(char **arcgs);
int bu_path(char **av, char **aa);
int env_path(char **av, char **aa);
char *location(char *path, char **av);
void free_list(char ***av);
int is_char(char *t);
void error_msg(char **aa, char **av);
int pwdp(char *cmd);
int _strlen(const char *cmd);
int _strcmp(const char *cmd, const char *c);
char *_strdup(char *cmd);
char *_strcat(char *des, char *src);
char *_strcpy(char *des, char *src);
char *_strchr(const char *des, const char *src);
char *_strtok(char *cmd, const char *de);
char *_getenv(const char *name);
int _atoi(const char *cmd);

#endif
