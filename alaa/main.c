#include "main.h"

/**
 * main - function that checks if shell is called
 * Return: 0 Always (successed)
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		my_interactive();
	}
	else
	{
		my_no_interactive();
	}
	return (0);
}
