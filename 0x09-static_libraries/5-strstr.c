#include "main.h"

/**
 * _strstr - Finds the first occurrence of the substring needle in the
 * string haystack. The terminating null bytes (\0) are not compared
 * @haystack: A pointer to the string to be searched
 * @needle: A pointer to the substring for which to be searched
 * Return: A pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j, needleLen = 0;

	while (needle[needleLen] != '\0')
		needleLen++;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0' && haystack[i + j] == needle[j]; j++)
			continue;
		if (needle[j] == '\0')
			return (haystack + i);
	}

	return (NULL);
}
