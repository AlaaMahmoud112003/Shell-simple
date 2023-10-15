#include "main.h"
/**
* _atoi - changes string into int
* @cmd : pointer to the string
* Return: int and 0 in failure
*/
int _atoi(const char *cmd)
{
	int l = 1;
	int res = 0;

	if (*cmd == '-')
	{
		cmd++;
		l = -1;
	}
	while (*cmd != '\0')
	{
		if (*cmd >= '0' && *cmd <= '9')
		{
			res = res * 10 + (*cmd - '0');
		}
		else
		{
			break;
		}
		cmd++;
	}
	if (l == -1)
	{
		return (res * l);
	}
	return (res);
}
