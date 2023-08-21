#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: A string
 */
void rev_string(char *s)
{
	int i, j, len = 0;
	char tmp;

	while (s[len] != '\0')
		len++;
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
