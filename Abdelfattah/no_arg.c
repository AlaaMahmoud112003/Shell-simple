#include "main.h"
/**
* no_arg - counts the number of the arguments
* @cmd : pointer to the input user
* Return: number of the arguments
*/
ssize_t no_arg(char *cmd)
{
	char *cmd_c = NULL;
	char *token = NULL;
	ssize_t n = 0;


	cmd_c = _strdup(cmd);
	token = _strtok(cmd_c, TO_DEL);
	while (token)
	{
		n++;
		token = _strtok(NULL, TO_DEL);
	}
	free(cmd_c);
	return (n);
}
