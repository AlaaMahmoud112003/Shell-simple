#include "main.h"
/**
* _strlen - counts the number of charactes
* @cmd : pointer to a string
* Return: int number of the status
*/
int _strlen(const char *cmd)
{
	int i = 0;

	while (*cmd)
	{
		i++;
		cmd++;
	}
	return (i);
}
