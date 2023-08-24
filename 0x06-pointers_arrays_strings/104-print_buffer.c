#include "main.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * print_buffer - Prints a buffer
 * @b: A pointer to a buffer (char array)
 * @size: The number of bytes in the buffer
 */
void print_buffer(char *b, int size)
{
	int i, j, l = 0;
	unsigned char *b2 = (unsigned char*) b;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", l);
		for (j = 0; j < 10; j++)
		{
			if (j % 2 == 0 && j != 0)
				printf(" ");
			if (i + j < size)
				printf("%02x", b2[i + j]);
			else
				printf("  ");
		}

		printf(" ");

		for (j = 0; j < 10; j++)
		{
			if (i + j < size)
			{
				if (isprint(b2[i + j]))
					printf("%c", b2[i + j]);
				else
					printf(".");
			}
		}
		l += 10;
		printf("\n");
	}
}
