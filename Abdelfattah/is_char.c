#include "main.h"
/**
* is_char - checks for char
* @t : pointer to the status
* Return: 0 in success
*/
int is_char(char *t)
{
	if (t)
	{
		if (*t >= 48 && *t <= 57)
		{
			return (0);
		}
		if (*t >= 65 && *t <= 90)
		{
			return (1);
		}
		if (*t >= 97 && *t <= 122)
		{
			return (1);
		}
		if (_atoi(t) < 0)
		{
			return (1);
		}
	}
	return (0);
}
