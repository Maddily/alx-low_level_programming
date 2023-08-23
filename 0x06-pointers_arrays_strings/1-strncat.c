#include "main.h"

/**
 * _strncat - Concatenates two strings
 * @dest: Main string
 * @src: String to be appended to dest
 * @n: Number of bytes in src to be appended
 * Return: A pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int destLen = 0, srcLen, i;

	while (dest[destLen] != '\0')
		destLen++;
	srcLen = 0;
	while (src[srcLen] != '\0')
		srcLen++;
	if (n > srcLen)
		n = srcLen;
	for (i = 0; i < n; i++)
		dest[destLen + i] = src[i];
	dest[destLen + i] = '\0';
	return (dest);
}
