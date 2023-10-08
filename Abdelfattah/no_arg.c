#include "main.h"
/*
*
*/
ssize_t no_arg(char *cmd)
{
	char *cmd_c = NULL;
	char *token = NULL;
	ssize_t n = 0;


	cmd_c = strdup(cmd);
	token = strtok(cmd_c, TO_DEL);
	while (token)
	{
		n++;
		token = strtok(NULL, TO_DEL);
	}
	free(cmd_c);
	return (n);
}

