#include <stdlib.h>
#include "main.h"

/**
 * findStringSize - Finds the size of a string
 * @s: A pointer to a string
 * Return: The size of s
 */
int findStringSize(char *s)
{
	int size = 1;

	while (s[size - 1] != '\0')
		size++;

	return (size);
}

/**
 * str_concat - Concatenates two strings
 * @s1: A pointer to the first string
 * @s2: A pointer to the second string
 * Return: A pointer to a newly allocated space in memory
 * containing the concatenated string
 */
char *str_concat(char *s1, char *s2)
{
	char *s;
	int s1Size, s2Size, i, j;

	s1Size = (s1 != NULL) ? findStringSize(s1) : 1;
	s2Size = (s2 != NULL) ? findStringSize(s2) : 1;

	s = malloc((s1Size * sizeof(char)) + (s2Size * sizeof(char)) - 1);

	if (s == NULL)
		return (NULL);

	for (i = 0; i < (s1Size - 1); i++)
		s[i] = s1[i];

	for (j = 0; j < (s2Size - 1); i++, j++)
		s[i] = s2[j];

	s[i] = '\0';

	return (s);
}
