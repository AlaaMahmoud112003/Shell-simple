#include "main.h"
/*
*
*/
char *location(char *path, char **av)
{
	char *fcmd = NULL;
	char *path_c = NULL;
	char *token = NULL;

	path_c = strdup(path);
	if (!path_c)
	{
		free(path_c);
		return (NULL);
	}
	token = strtok(path_c, ":");
	while (token)
	{
		fcmd = malloc((strlen(token) + strlen(av[0]) + 2) * sizeof(char));
		if (!fcmd)
		{
			free(fcmd);
			free(path_c);
			perror("Error");
			return (NULL);
		}
		strcpy(fcmd, token);
		strcat(fcmd, "/");
		strcat(fcmd, av[0]);
		if (access(fcmd, F_OK) == 0)
		{
			free(path_c);
			return (fcmd);
		}
		free(fcmd);
		token = strtok(NULL, ":");
	}
	free(path_c);
	if (access(av[0], F_OK) == 0)
	{
		return (strdup(av[0]));
	}
	return (NULL);
}

