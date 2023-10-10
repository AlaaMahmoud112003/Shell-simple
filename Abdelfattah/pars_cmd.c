#include "main.h"
/**
* pars_cmd - build a path for the command
* @cmd : pointer to the input user
* @r : the number of the arguments
* @av : pointer to a double pointer to the arguments
*/
void pars_cmd(char *cmd, ssize_t r, char ***av)
{
	char *token;
	int i = 0;
	int l;


	*av = malloc(sizeof(char *) * (r + 1));
	if (!(*av))
	{
		free(*av);
		return;
	}
	token = _strtok(cmd, TO_DEL);
	while (token)
	{
		(*av)[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (!(*av)[i])
		{
			l = 0;
			while (l < i)
			{
				free((*av)[l]);
				l++;
			}
			free(*av);
			return;
		}
		_strcpy((*av)[i], token);
		token = _strtok(NULL, TO_DEL);
		i++;
	}
	(*av)[i] = NULL;
}
