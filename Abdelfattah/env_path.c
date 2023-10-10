#include "main.h"
/**
* env_path - build a path for the command
* @av : double pointer to arguments
* @aa :  non-interactive double pointer to the arguments
* Return: int number of the status
*/
int env_path(char **av, char **aa)
{
	char *path = getenv("PATH");
	pid_t i;
	int l, status;
	char *cmd = NULL;

	if (!av)
		return (EXIT_FAILURE);
	cmd = location(path, av);
	if (!cmd)
	{
		free(cmd);
		error_msg(aa, av);
		return (127);
	}
	else
	{
		i = fork();
		if (i == -1)
		{
			free(cmd);
			perror("Error");
			return (-2);
		}
		if (i == 0)
		{
			if (execve(cmd, av, environ) == -1)
				status = EXIT_FAILURE;
			exit(status);
		}
		else
		{
			waitpid(i, &l, WUNTRACED);
			free(cmd);
			if (WIFEXITED(l))
				return (WEXITSTATUS(l));
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_FAILURE);
}
