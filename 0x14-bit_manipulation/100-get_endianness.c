#include "main.h"

/**
 * get_endianness - Checks a system's endianness.
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int number = 1;
	char *byte = (char *)&number;

	if (*byte)
		return (1);
	else
		return (0);
}
