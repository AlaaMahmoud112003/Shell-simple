#include "main.h"
/*
*
*/
int env_path(char **av)
{
	char *path = getenv("PATH");
	pid_t i;
	char *cmd = NULL;

	if (!av)
	{
		return(0);
	}
	cmd = location(path, av);
	if (!cmd)
	{
        perror("Error");
		return (2);
	}
	else
	{
		i = fork();
		if (i == -1)
		{
			free(cmd);
			perror("Error");
			return (-1);
		}
		if (i == 0)
		{
			if (execve(cmd, av, environ) == -1)
			{
				free(cmd);
				perror("error");
				return (-1);
			}
		}
		else
		wait(NULL);
		free(cmd);
        return (0);
	}
	return (0);
}

