#include "main.h"

/**
 * my_cd - function that changes the working current shell executon 
 * @arcgs: arcgs
 * Return: -1 .
 */
int my_cd(char **arcgs)
{
	if (arcgs[1] == NULL)
	{
		fprintf(stderr, " the expected arguments to \"cd\"\n");
	}
	else
	{
		if (chdir(arcgs[1]) != 0)
		{
			perror("error in my_cd.c: changing the dir\n");
		}
	}
	return (0);
}

/**
 * my_env - function that prints enviroment variables
 * @arcgs: arcgs
 * Return: -1
 */
int my_env(char **arcgs)
{
	int g = 0;
	(void)(**arcgs);

	while (environ[g])
	{
		write(STDOUT_FILENO, environ[g], strlen(environ[g]));
		write(STDOUT_FILENO, "\n", 1);
		g++;
	}
	return (0);
}

/**
 * my_exit - function that couses normal process termin
 * @arcgs: arcgs
 * Return: 0
 */
int my_exit(char **arcgs)
{
	if (arcgs[1])
	{
		return (atoi(arcgs[1]));
	}

	else
	{
		return (0);
	}
}

