#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Main string
 * @src: String to be appended to dest
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int destLen = 0, srcLen, i;

	while (dest[destLen] != '\0')
		destLen++;
	srcLen = 0;
	while (src[srcLen] != '\0')
		srcLen++;
	for (i = 0; i < srcLen; i++)
		dest[destLen + i] = src[i];
	dest[destLen + i] = '\0';
	return (dest);
}
