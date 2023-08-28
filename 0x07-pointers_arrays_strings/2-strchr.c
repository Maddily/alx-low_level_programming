#include "main.h"

#define NULL ((void *)0)

/**
 * _strchr - Locates a character in a string
 * @s: A pointer to a string to be searched
 * @c: A character for which to be searched
 * Return: A pointer to the first occurrence of c in s, NULL if c isn't found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return (s + i);
	if (c == '\0')
		return (s + i);
	return (NULL);
}
