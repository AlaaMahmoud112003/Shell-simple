#include "main.h"
/**
* location - search for the command in the path
* @path : pointer to path
* @av : double pointer to the command and arguments
* Return: pointer to the command full path
*/
char *location(char *path, char **av)
{
	char *fcmd = NULL;
	char *path_c = NULL;
	char *token = NULL;

	if (path)
	{
		path_c = _strdup(path);
		if (!path_c)
		{
			free(path_c);
			return (NULL);
		}
		token = _strtok(path_c, ":");
		while (token)
		{
			fcmd = malloc((_strlen(token) + _strlen(av[0]) + 2) * sizeof(char));
			if (!fcmd)
			{
				free(fcmd), free(path_c);
				perror("Error");
				return (NULL);
			}
			_strcpy(fcmd, token), _strcat(fcmd, "/"), _strcat(fcmd, av[0]);
			if (access(fcmd, F_OK) == 0)
			{
				free(path_c);
				return (fcmd);
			}
			free(fcmd);
			token = _strtok(NULL, ":");
		}
		free(path_c);
	}
	if (access(av[0], F_OK) == 0)
	{
		if (pwdp(av[0]) == 0)
			return (_strdup(av[0]));
	}
	return (NULL);
}
