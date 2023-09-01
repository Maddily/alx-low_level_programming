#include "main.h"

/**
 * _strcpy - Copies src to dest
 * @dest: A pointer to a buffer
 * @src: A pointer to a string
 * Return: A pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i, len = 0;

	while (src[len] != '\0')
		len++;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[len] = '\0';
	return (dest);
}
