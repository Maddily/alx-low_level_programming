#include <stdlib.h>
#include "main.h"

/**
 * argstostr - Concatenates all arguments of a program
 * @ac - Argument count
 * @av: A pointer to the first argument
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, size = 0;
	char *s;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			size++;

		size++;
	}

	s = malloc((size + 1) * sizeof(char));

	if (s == NULL)
		return (NULL);

	k = 0;

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, k++)
			s[k] = av[i][j];

		s[k++] = '\n';
	}

	s[k] = '\0';

	return (s);
}
