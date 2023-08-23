#include "main.h"

/**
 * rot13 - Encodes a string using rot13
 * @str: A pointer to a string
 * Return: A pointer to the string, encoded
 */
char *rot13(char *str)
{
	int i;
	/* char lower[] = "abcdefghijklmnopqrstuvwxyz"; */
	/* char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; */
	char *l = "nopqrstuvwxyzabcdefghijklm";
	char *u = "NOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = l[str[i] - 'a'];
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = u[str[i] - 'A'];
		}
	}
	return (str);
}
