#include "main.h"

/**
 * _strspn - Finds the length of a prefix substring
 * @s: A pointer to the string to be scanned
 * @accept: A pointer to the set of characters to match
 * Return: The length of the initial segment of the string s
 * that consists only of characters from the set accept
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j;
	unsigned int len = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
			if (s[i] == accept[j])
			{
				len++;
				break;
			}
		if (s[i] != accept[j])
			break;
	}

	return (len);
}
