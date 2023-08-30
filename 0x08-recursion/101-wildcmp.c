#include "main.h"

/**
 * wildcmp - Checks if two strings can be considered identical
 * @s1: A pointer to a string
 * @s2: A pointer to a string
 * Return: 1 if the strings can be considered identical and 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == '\0' || *s2 == '\0')
		return (0);

	if (*s1 == *s2 || *s2 == '*')
		return (wildcmp(s1 + 1, s2 + 1) || wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));

	return (0);
}
