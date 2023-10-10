#include "main.h"
/**
* _strcat - concatenates to the end of a string
* @des : pointer to a string
* @src : pointer to the source
* Return: pointer to the copied string
*/
char *_strcat(char *des, char *src)
{
	char *a = des;

	while (*des)
	{
		des++;
	}
	while (*src)
	{
		*des++ = *src++;
	}
	*des = '\0';
	return (a);
}
