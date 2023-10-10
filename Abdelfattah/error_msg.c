#include "main.h"
/**
* error_msg - prints an error message
* @av : double pointer to arguments
* @aa :  non-interactive double pointer to the arguments
*/
void error_msg(char **aa, char **av)
{
	write(STDERR_FILENO, aa[0], _strlen(aa[0]));
	write(STDERR_FILENO, ": 1: ", _strlen(": 1: "));
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": not found\n", _strlen(": not found\n"));
}
