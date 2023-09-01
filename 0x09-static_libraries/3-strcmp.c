#include "main.h"

/**
 * _strcmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * Return: The difference between the first character of s1 and s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	if (sizeof(s1) > sizeof(s2))
		return ((int)(s1[i]));
	else if (sizeof(s1) < sizeof(s2))
		return ((int)(s2[i]));
	else
		return (0);
}
