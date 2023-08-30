#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string
 * @s: A pointer to a string
 * Return: The length of the string pointed to by s
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
