#include "main.h"
/**
* free_list - frees the memory after usage
* @av :  pointer to a double pointer to the arguments
*/
void free_list(char ***av)
{
	int d = 0;

	while ((*av)[d] != NULL)
	{
		free((*av)[d]);
		d++;
	}
	free((*av));
}

