#include "main.h"

/**
 * swap_int - Swaps the values of two integers
 * @a: A pointer to an integer
 * @b: A pointer to an integer
 */
void swap_int(int *a, int *b)
{
	int c = *a;

	*a = *b;
	*b = c;
}
