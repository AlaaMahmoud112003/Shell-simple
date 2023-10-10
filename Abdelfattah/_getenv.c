#include "main.h"
/**
* _getenv - get a specific env variable
* @name : pointer to the name of the variable
* Return: pointer to the variable
*/
char *_getenv(const char *name)
{
	char *e, *d;
	char **en = environ;

	if (!name)
	{
		return (NULL);
	}
	while (*en)
	{
		if (*en && _strcmp(*en, name) == 0)
		{
			e = _strchr(*en, "=");
			if (e != NULL)
			{
				e++;
				d = malloc((_strlen(e) + 1) * sizeof(char));
				if (d != NULL)
				{
					_strcpy(d, e);
					return (d);
				}
			}
		}
		en++;
	}
	return (NULL);
}
