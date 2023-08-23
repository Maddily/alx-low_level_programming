#include "main.h"

/**
 * rot13 - Encodes a string using rot13
 * @str: A pointer to a string
 * Return: A pointer to the string, encoded
 */
char *rot13(char *str)
{
	int i;
	char *l = "nopqrstuvwxyzabcdefghijklm";
	char *u = "NOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = l[str[i] - 'a'];
			else
				str[i] = u[str[i] - 'A'];
		}
	}
	return (str);
}
