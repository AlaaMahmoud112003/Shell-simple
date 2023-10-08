#include "main.h"
/*
*
*/
int main(int ac, char **av)
{
	char *cmd = NULL;
	size_t n = 0;
	ssize_t r;
	int m;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("$) ");
		if ((r = getline(&cmd, &n, stdin)) == EOF)
		{
			free(cmd);
			break;
		}
		r = no_arg(cmd);
		if (r != 0)
		{
			pars_cmd(cmd, r, &av);
			m = bu_path(av);
			if (m == 1)
			{
				env_path(av);
				free_list(&av);
			}
			else if (m == 0)
			{
				free_list(&av);
				free(cmd);
				exit(m);
			}
			else
			{
				free_list(&av);
			}
		}
	}
	return (0);
}

