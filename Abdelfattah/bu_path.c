#include "main.h"
/**
* bu_path - checks if the command built-in
* @av : double pointer to arguments
* @aa : non-interactive double pointer to the arguments
* Return: int number of the status
*/
int bu_path(char **av, char **aa)
{
	int i;
	char *builtin[4] = {"cd", "env", "exit", NULL};

	int (*builtinexe[])(char **) = {
		&my_cd,
		&my_env,
		&my_exit,
		NULL
	};
	if (!av || av[0] == NULL)
	{
		return (-1);
	}
	i = 0;
	while (builtin[i] != NULL)
	{
		if (_strcmp(builtin[i], av[0]) == 0)
		{
			return ((*builtinexe[i])(av));
		}
		i++;
	}
	return (env_path(av, aa));
}
