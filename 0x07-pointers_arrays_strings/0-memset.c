#include "main.h"

/**
 * _memset - Fills the first n bytes of the memory area pointed to by s
 * with the constant byte b
 * @s: A pointer to the block of memory to be filled
 * @b: The value to be filled
 * @n: The number of bytes in memory to be filled
 * Return: A pointer to the filled block of memory
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i;

	for (i = 0; i < (int)n; i++)
		s[i] = b;

	return (s);
}
