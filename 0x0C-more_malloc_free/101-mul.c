#include <stdlib.h>
#include "main.h"

/**
 * findLength - Finds the length of a string
 * @str: A pointer to a string
 * Return: The length of the string str
 */
int findLength(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * checkDigit - Checks if a string consists of nothing but digits
 * @num: A pointer to a string
 * Return: 0 if successful or terminates with an error if not
 */
int checkDigit(char *num)
{
	int i;

	for (i = 0; i < findLength(num); i++)
	{
		if (num[i] < '0' || num[i] > '9')
		{
			printError();
			exit(98);
		}
	}

	return (0);
}

/**
 * printError - Prints "Error", followed by a new line
 */
void printError(void)
{
	char *error = "Error\n";

	while (*error != '\0')
	{
		_putchar(*error);
		error++;
	}
}

/**
 * initString - Initializes all bytes in a string to 0
 * @s: A pointer to a string
 * @bytes: The number of bytes
 */
void initString(char *s, int bytes)
{
	int i;

	for (i = 0; i < bytes; i++)
		s[i] = '0';
}

/**
 * multiply - Multiplies two numeric strings
 * @i: num1 index
 * @j: num2 index
 * @num1len: The length of num1
 * @num2len: The length of num2
 * @carry: The carried number after multiplication
 * @product: The product
 * @num1: The first number
 * @num2: The second number
 * @result: The result of multiplication
 */
void multiply(int i, int j, int num1len, int num2len, int carry, int product,
		char *num1, char *num2, char *result)
{
	for (i = num1len - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = num2len - 1; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0') +
				(result[i + j + 1] - '0') + carry;
			result[i + j + 1] = (product % 10) + '0';
			carry = product / 10;
		}
		result[i + j + 1] = (carry % 10) + '0';
	}
}

/**
 * printResult - Prints the result
 * @start: The first digit
 * @maxResultLen: The max length of the result
 * @i: index
 * @result: A pointer to the result
 */
void printResult(int start, int maxResultLen, int i, char *result)
{
	if (start == maxResultLen)
	{
		_putchar('0');
	}
	else
	{
		for (i = start; i < maxResultLen; i++)
		{
			_putchar(result[i]);
		}
	}

	_putchar('\n');

	free(result);
}

/**
 * main - Multiplies two numbers
 * @argc: The number of arguments
 * @argv: A pointer to an array of arguments
 * Return: 0 if successful, 98 if not
 */
int main(int argc, char *argv[])
{
	char *num1 = argv[1];
	char *num2 = argv[2];
	int i = 0, j = 0, carry = 0, product = 0, resultAlloc = 0;
	int start = 0;
	int num1len = findLength(num1);
	int num2len = findLength(num2);
	int maxResultLen = num1len + num2len;
	char *result = malloc((maxResultLen + 1) * sizeof(char));

	if (result == NULL)
	{
		printError();
		return (98);
	}

	resultAlloc = 1;

	if (argc != 3 || checkDigit(num1) != 0 || checkDigit(num2) != 0)
	{
		printError();

		if (resultAlloc)
			free(result);

		return (98);
	}
	initString(result, maxResultLen + 1);

	multiply(i, j, num1len, num2len, carry, product, num1, num2, result);

	/* Find the first non-zero digit in the result */
	while (start < maxResultLen && result[start] == '0')
	{
		start++;
	}

	printResult(start, maxResultLen, i, result);

	return (0);
}
