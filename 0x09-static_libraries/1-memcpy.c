#include "main.h"

/**
 * _memcpy - Copies a block of memory
 * @dest: A pointer to the destination memory location
 * @src: A pointer to the source memory location
 * @n: The number of bytes to be copied
 * Return: A pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
