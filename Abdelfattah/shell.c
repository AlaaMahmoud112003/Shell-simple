#include "main.h"
/**
* main - the main function for the simple shell
* @ac : the number of arguments
* @av : double pointer to the arguments
* Return: 0 in success
*/
int main(int ac, char **av)
{
	char *cmd = NULL;
	char **aa;
	size_t n = 0;
	ssize_t r;
	int m;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$) ", _strlen("$) "));
		r = getline(&cmd, &n, stdin);
		if (r == EOF)
		{
			free(cmd);
			break;
		}
		r = no_arg(cmd);
		if (r != 0 && isatty(STDIN_FILENO) == 1)
		{
			pars_cmd(cmd, r, &aa);
			m = bu_path(aa, av);
			if (_strcmp(aa[0], "exit") == 0 && is_char(aa[1]) == 0)
			{
				free_list(&aa), free(cmd), exit(m);
			}
			free_list(&aa);
		}
		if (isatty(STDIN_FILENO) == 0)
		{
			pars_cmd(cmd, r, &aa);
			m = bu_path(aa, av);
			if (aa == NULL || m >= 2)
			{
				free_list(&aa), free(cmd), exit(m);
			}
			free_list(&aa);
		}
	}
	return (0);
}
