#include "main.h"
/*
*
*/
int bu_path(char **av)
{
	int i;
	char *builtin[4] = {"cd", "env", "exit", NULL};
	int (*builtinexe[])(char **) =
	{
		&my_cd,
		&my_env,
		&my_exit,
		NULL
	};
	if (av[0] == NULL)
	{
		return (1);
	}
	i = 0;
	if (av == NULL)
	{
		return (1);
	}
	while (builtin[i] != NULL)
	{
		if (strcmp(builtin[i], av[0]) == 0)
		{
			return ((*builtinexe[i])(av));
		}
		i++;
	}
	return (1);
}

