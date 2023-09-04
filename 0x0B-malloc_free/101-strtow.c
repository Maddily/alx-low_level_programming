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
 * @words: Word count
 * @i: index
 * @j: index
 * @k: index
 * @l: index
 * @wordLen: Word length
 * @str: A pointer to the string to be split into words
 * @arr: A pointer to an array of pointers
 */
void addWord(int words, int i, int j, int k, int l, int wordLen, char *str,
		char **arr)
{
	for (i = 0; i < words; i++)
	{
		wordLen = 0;

		for (k = k; str[k] != '\0'; k++)
		{
			if (str[k] == ' ')
				continue;
			else
			{
				wordLen++;

				if (str[k + 1] == ' ')
					break;
			}
		}

		if (wordLen > 0)
		{
			l = k - wordLen + 1;
			k++;
			arr[i] = malloc((wordLen + 1) * sizeof(char));

			for (j = 0; j < wordLen; j++)
			{
				arr[i][j] = str[l++];
			}

			arr[i][j] = '\0';
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
	int i, j, k, l, words = 0, wordLen;
	char **arr;

	if (str == NULL || findLength(str) == 0)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		while (str[i] != ' ' && str[i] != '\0')
		{
			i++;
			if (str[i] == ' ' || str[i] == '\0')
				words++;
		}
	}

	if (words == 0)
		return (NULL);

	arr = malloc((words + 1) * sizeof(char *));

	if (arr == NULL)
		return (NULL);

	j = 0, k = 0, l = 0, wordLen = 0;

	addWord(words, i, j, k, l, wordLen, str, arr);

	arr[i] = NULL;

	return (arr);
}
