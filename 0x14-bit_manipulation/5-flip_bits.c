#include "main.h"

/**
 * flip_bits - Finds the number of bits that need to be flipped to get
 * from one number to another.
 * @n: The first number
 * @m: The second number
 *
 * Return: The number of bits to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff;
	int ones = 0;

	diff = n ^ m;
	while (diff > 0)
	{
		ones += diff & 1;
		diff >>= 1;
	}

	return (ones);
}
