#include "main.h"

/**
 * read_cmd - function that read a command line from stdin
 * Return: linecmd
 */
char *read_cmd(void)
{
 char *linecmd = NULL;
 size_t buffer_size = 0;

 if (getline(&linecmd, &buffer_size, stdin) == -1) 
 {
  if (feof(stdin)) 
  {
   free(linecmd);
   exit(EXIT_SUCCESS);
  }
  else
  {
   free(linecmd); 
   perror("error reading the line");
   exit(EXIT_FAILURE);
  }
 }
 return (linecmd);
}
/**
 * my_read - function that read a line
 * Return: void
 */
char *my_read(void)
{
	int buffer_size = 1024;
	int u = 0;
	char *linecmd = malloc(sizeof(char) * buffer_size);
	int chara;

	if (linecmd == NULL)
	{
		fprintf(stderr, "allocation error in my_read");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		chara = getchar();
		if (chara == EOF)
		{
			free(linecmd);
			exit(EXIT_SUCCESS);
		}
		else if (chara == '\n')
		{
			linecmd[u] = '\0';
			return (linecmd);
		}
		else
		{
			linecmd[u] = chara;
		}
		u++;
		if (u >= buffer_size)
		{
			buffer_size += buffer_size;
			linecmd = realloc(linecmd, buffer_size);
			if (linecmd == NULL)
			{
				fprintf(stderr, "reallocation error in my_read");
				exit(EXIT_FAILURE);
			}
		}
	}
}
