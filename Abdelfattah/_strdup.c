#include "main.h"
/**
* _strdup - dublicates a sring
* @cmd : pointer to a string
* Return: pointer to the dublicated string
*/
char *_strdup(char *cmd)
{
	char *cp;

	if (!cmd)
	{
		return (NULL);
	}
	cp = malloc((_strlen(cmd) + 1) * sizeof(char));
	if (!cp)
	{
		return (NULL);
	}
	_strcpy(cp, cmd);
	return (cp);
}
