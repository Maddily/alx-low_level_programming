#include <stdlib.h>
#include "main.h"

/**
 * findLength - Finds the length of a string
 * @str: A pointer to a string
 * Return: The length of a string
 */
int findLength(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * addWord - Adds words to array of words arr
 * @i: index
 * @j: index
 * @k: index
 * @l: index
 * @wordLen: Word length
 * @str: A pointer to the string to be split into words
 * @arr: A pointer to an array of pointers
 */
void addWord(int i, int j, int k, int l, int wordLen, char *str,
		char **arr)
{
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;

		if (str[i] != '\0')
		{
			wordLen = 0;
			j = i;

			while (str[j] != ' ' && str[j] != '\0')
			{
				wordLen++;
				j++;
			}

			arr[k] = malloc((wordLen + 1) * sizeof(char));

			if (arr[k] == NULL)
				exit(1);

			for (l = 0; l < wordLen; l++)
				arr[k][l] = str[i++];

			arr[k][l] = '\0';
			k++;
		}
	}
}

/**
 * strtow - Splits a string into words
 * @str: A pointer to a string
 * Return: A pointer to an array of strings
 */
char **strtow(char *str)
{
	int i, j, k, l, words = 0, wordLen = 0;
	char **arr;

	if (str == NULL || findLength(str) == 0)
		return (NULL);

	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;

		if (str[i] != '\0')
		{
			words++;

			while (str[i] != ' ' && str[i] != '\0')
				i++;
		}
	}
	if (words == 0)
		return (NULL);

	arr = malloc((words + 1) * sizeof(char *));

	if (arr == NULL)
		return (NULL);

	i = 0, j = 0, k = 0, l = 0;

	addWord(i, j, k, l, wordLen, str, arr);

	arr[words] = NULL;

	return (arr);
}
