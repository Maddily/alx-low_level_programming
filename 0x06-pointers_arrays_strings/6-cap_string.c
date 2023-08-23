#include "main.h"
#define CONDITION	((prev == ' ' || prev == ',' || prev == ';' || \
			prev == '.' || prev == '!' || prev == '?' || \
			prev == '\t' || prev == '(' || prev == ')' || \
			prev == '{' || prev == '}' || prev == '\n' || \
			prev == '"') && (str[i] >= 'a' && str[i] <= 'z'))

/**
 * cap_string - Capitalizes all words of a string
 * @str: A string
 * Return: The string, capitalized
 */
char *cap_string(char *str)
{
	int i;
	char prev;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		else
		{
			prev = str[i - 1];
			if (CONDITION)
				str[i] -= 32;
		}
		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (str);
}
