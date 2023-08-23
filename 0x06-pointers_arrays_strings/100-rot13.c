#include "main.h"

/**
 * rot13 - Encodes a string using rot13
 * @str: A pointer to a string
 * Return: A pointer to the string, encoded
 */
char *rot13(char *str)
{
	int i, j;
	char rot1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; rot1[j] != '\0'; j++)
		{
			if (str[i] == rot1[j])
			{
				str[i] = rot2[j];
				break;
			}

		}
	}
	return (str);
}
