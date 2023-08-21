#include "main.h"

/**
 * _strlen - Finds the length of a string
 * @s: A string
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}

	return (len);
}
