#include <stdlib.h>
#include "main.h"

/**
 * _strlen - Finds the length of a string
 * @s: A pointer to a string
 * Return: The length of the string s
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * string_nconcat - Concatenates two strings
 * @s1: A pointer to the first string
 * @s2: A pointer to the second string
 * @n: The number of bytes in s2 to be concatenated with s1
 * Return: A pointer to the concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int s1Len, s2Len, i, j;
	char *concat_str;

	s1Len = (s1 == NULL) ? 0 : _strlen(s1);
	s2Len = (s2 == NULL) ? 0 : _strlen(s2);

	if (n >= s2Len)
		n = s2Len;

	concat_str = malloc((s1Len + n + 1) * sizeof(char));

	if (concat_str == NULL)
		return (NULL);

	for (i = 0; i < s1Len; i++)
		concat_str[i] = s1[i];

	for (j = 0; j < n; i++, j++)
		concat_str[i] = s2[j];

	concat_str[i] = '\0';

	return (concat_str);
}
