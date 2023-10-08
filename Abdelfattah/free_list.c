#include "main.h"
/*
*
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

