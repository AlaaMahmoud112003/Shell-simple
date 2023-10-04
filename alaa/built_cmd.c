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
	return (-1);
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
	return (-1);
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


/**
 * my_help - function that print help
 * @arcgs: arguments
 * Return: 1 or 0
 */
int my_help(char **arcgs)
{
	char *built_function_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	long unsigned int v = 0;
	(void)(**arcgs);

	printf("\n---help in simple_shell---\n");
	printf(" that type command and its the arguments, then hit enter\n");
	printf("built-in command line:\n");
	for (; v < sizeof(built_function_list) / sizeof(char *); v++)
	{
		printf("  -> %s\n", built_function_list[v]);
	}
	printf("use man command for information on other program.\n\n");
	return (-1);
}
