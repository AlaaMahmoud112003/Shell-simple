#include "main.h"
/**
* pwdp - checks for the path
* @cmd : pointer to the command
* Return: 0 in success 1 in failure
*/
int pwdp(char *cmd)
{
	int i = 0;

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '/')
		{
			return (0);
		}
	}
	return (1);
}
