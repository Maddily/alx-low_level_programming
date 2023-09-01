#include "main.h"

/**
 * _isupper - Checks if a character is uppercase or lowercase
 * Return: Returns 1 if uppercase or 0 if lowercase
 * @c: The character to be checked
 */
int _isupper(int c)
{
	return ((c >= 65 && c <= 90) ? 1 : 0);
}
