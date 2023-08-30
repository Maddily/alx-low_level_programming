#include "main.h"

/**
 * _strlen - Calculates the length of a string
 * @s: A pointer to a string
 * Return: The length of s
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}

/**
 * pal_helper - Checks if a string is a palindrome
 * @s: A pointer to a string
 * @start: The start index
 * @end: The end index
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int pal_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (pal_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: A pointer to a string
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int start = 0;
	int end = _strlen(s) - 1;

	return (pal_helper(s, start, end));
}
