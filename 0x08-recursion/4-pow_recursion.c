#include "main.h"

/**
 * _pow_recursion - Finds the value of a number raised to a power
 * @x: The base number
 * @y: The power
 * Return: The value of x raised to the power of y
 */
int _pow_recursion(int x, int y)
{
	if (x == 1 || (y == 0 && x >= 0))
		return (1);
	if ((y == 0 && x < 0) || y < 0)
		return (-1);
	return (-x * _pow_recursion(x, y - 1));
}
