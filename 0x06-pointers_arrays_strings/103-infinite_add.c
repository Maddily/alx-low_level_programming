#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: First number
 * @n2: Second number
 * @r: The result
 * @size_r: The size of r
 * Return: A pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int n1len, n2len, maxLen, carry, s, i, j, k;

	n1len = 0;
	while (n1[n1len] != '\0')
		n1len++;
	n2len = 0;
	while (n2[n2len] != '\0')
		n2len++;
	maxLen = (n1len > n2len) ? n1len : n2len;
	if ((maxLen + 2) > size_r)
		return ((char *)0);
	carry = 0;
	i = n1len - 1, j = n2len - 1, k = maxLen;
	while (i >= 0 || j >= 0)
	{
		s = carry + ((i >= 0) ? (n1[i] - '0') : 0) + ((j >= 0) ? (n2[j] - '0') : 0);
		if (s > 9)
		{
			s -= 10;
			carry = 1;
		}
		else
			carry = 0;
		r[k--] = s + '0';
		i--, j--;
	}
	if (carry)
		r[k] = carry + '0';
	else
		k++;
	return (r);
}
