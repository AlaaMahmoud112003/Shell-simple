#include "main.h"
/**
* _strcmp - compares between two strings
* @cmd : pointer to a string
* @c : pointer to the second string
* Return: int number of the status
*/
int _strcmp(const char *cmd, const char *c)
{
	while (*cmd && *c)
	{
		if (*cmd != *c)
		{
			return (*cmd - *c);
		}
		cmd++;
		c++;
	}
	return (0);
}
