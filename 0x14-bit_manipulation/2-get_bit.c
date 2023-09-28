#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: A base 10 number
 * @index: The index (starting from 0) of the bit whose value is to be returned
 *
 * Return: The value of the bit at the given index, or -1 on failure.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	mask = 1 << index;

	if (n & mask)
		return (1);
	else
		return (0);
}
