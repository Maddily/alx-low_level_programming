#include <stdlib.h>
#include "main.h"

/**
 * create_array - Creates a char array and initializes it with a character
 * @size: The size of the array
 * @c: The character with which the array is to be initialized
 * Return: A pointer to the array or NULL if creating the array fails
 */
char *create_array(unsigned int size, char c)
{
	char *p;
	size_t i;

	if (size == 0)
		return (NULL);

	p = malloc(size * sizeof(char));

	if (p == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		p[i] = c;

	return (p);
}
