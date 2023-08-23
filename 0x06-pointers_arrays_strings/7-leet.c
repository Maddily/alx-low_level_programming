#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: A string
 * Return: The string, encoded
 */
char *leet(char *str)
{
	int i, j;
	char *ch = "aAeEoOtTlL";
	char *leet = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
		for (j = 0; ch[j] != '\0'; j++)
			if (str[i] == ch[j])
				str[i] = leet[j];
	return (str);
}
