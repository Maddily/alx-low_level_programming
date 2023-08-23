#include "main.h"

/**
 * _strncpy - Copies a string
 * @dest: First string
 * @src: String to be copied
 * @n: Number of bytes in src to be copied
 * Return: A pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (i >= 48 && i <= 90)
			dest[i] = 0;
		else
			dest[i] = src[i];
	}
	return (dest);
}
