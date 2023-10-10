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
		perror("Error");
	}
	else
	{
		if (chdir(arcgs[1]) != 0)
		{
			perror("Error in cd: changing the dir\n");
		}
	}
	return (1);
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
		write(STDOUT_FILENO, environ[g], _strlen(environ[g]));
		write(STDOUT_FILENO, "\n", 1);
		g++;
	}
	return (1);
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
		if (atoi(arcgs[1]) < 0 || (*arcgs[1] < 48 || *arcgs[1] > 57))
		{
			write(STDERR_FILENO, "./hsh: 1: ", _strlen("./hsh: 1: "));
			write(STDERR_FILENO, "exit: ", _strlen("exit: "));
			write(STDERR_FILENO, "Illegal number: ", _strlen("Illegal number: "));
			write(STDERR_FILENO, arcgs[1], _strlen(arcgs[1]));
			write(STDERR_FILENO, "\n", 1);
			return (-2);
		}
		return (atoi(arcgs[1]));
	}

	else
	{
		return (0);
	}
}

