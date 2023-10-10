#include "main.h"
/**
* _strcpy - copies a string to another
* @des : pointer to a string
* @src : pointer to the source
* Return: pointer to the copied string
*/
char *_strcpy(char *des, char *src)
{
	char *a = src;

	while (*src != '\0')
	{
		*des++ = *src++;
	}
	*des = '\0';
	return (a);
}
