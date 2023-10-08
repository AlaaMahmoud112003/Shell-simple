#include "main.h"
/*
*
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
	token = strtok(cmd, TO_DEL);
	while (token)
	{
		(*av)[i] = malloc(sizeof(char) * (strlen(token) + 1));
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
		strcpy((*av)[i], token);
		token = strtok(NULL, TO_DEL);
		i++;
	}
	(*av)[i] = NULL;
}

