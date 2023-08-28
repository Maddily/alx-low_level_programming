#include "main.h"

/**
 * _strpbrk - Locates the first occurrence in the string s
 * of any of the characters in the string accept
 * @s: A pointer to the string to be searched
 * @accept: A pointer to the set of characters
 * Return: A pointer to the character in s that matches
 * one of the characters in accept, NULL if none of the characters are found
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
			if (s[i] == accept[j])
				return (s + i);
	}

	return (NULL);
}
