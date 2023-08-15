#include "main.h"

/**
 * _islower - Checks if a character is lowercase
 * @c: An alphabetic character
 * Return: Returns 1 if it's a lowercase, 0 otherwise
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
