#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Prints the sum of the two diagonals
 * of a square matrix of integers
 * @a: A pointer to an array
 * @size: The size of the array
 */
void print_diagsums(int *a, int size)
{
	long d1, d2;
	int i;

	d1 = 0;
	for (i = 0; i < size * size; i += (size + 1))
		d1 += a[i];

	d2 = 0;
	for (i = size - 1; i < (size * size) - (size - 1); i += (size - 1))
		d2 += a[i];

	printf("%ld, %ld\n", d1, d2);
}
