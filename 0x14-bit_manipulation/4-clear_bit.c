#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: A pointer to a base 10 number
 * @index: The index (starting from 0) of the bit whose value is to be set
 *
 * Return: 1 on success, -1 on failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;

	if (n == NULL || (index >= (sizeof(unsigned long int) * 8)))
		return (-1);

	mask = ~(1 << index);
	*n = (*n) & mask;

	return (1);
}
