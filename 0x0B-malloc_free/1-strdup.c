#include <stdlib.h>
#include "main.h"

/**
 * findStringSize - Finds the size of a string
 * @str: A pointer to a string
 * Return: The size of a string
 */
int findStringSize(char *str)
{
	int size = 1;

	while (str[size - 1] != '\0')
		size++;

	return (size);
}

/**
 * _strdup - Copies a string
 * @str: A pointer to a string
 * Return: A pointer to the duplicate string, NULL if it fails to copy str,
 * or NULL if str doesn't point to a string
 */
char *_strdup(char *str)
{
	char *copy;
	int size, i;

	if (str == NULL)
		return (NULL);

	size = findStringSize(str);

	copy = malloc(size * sizeof(char));

	if (copy == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		copy[i] = str[i];

	return (copy);
}
