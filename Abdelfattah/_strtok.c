#include "main.h"
/**
* _strtok - splits a string into parts
* @cmd : pointer to a string
* @de : pointer to the delimiter characters
* Return: pointer to the 1st string split
*/
char *_strtok(char *cmd, const char *de)
{
	static char *c;
	char *a;

	if (cmd != NULL)
	{
		c = cmd;
	}
	if (!c || *c == '\0')
	{
		return (NULL);
	}
	while (*c && _strchr(de, c))
	{
		c++;
	}
	if (*c == '\0')
	{
		return (NULL);
	}
	a = c;
	while (*c && !_strchr(de, c))
	{
		c++;
	}
	if (*c == '\0')
	{
		c = NULL;
	}
	else
	{
		*c = '\0';
		c++;
	}
	return (a);
}
