#include "main.h"

/**
 * _sqrt - Finds the square root
 * Description: The function returns -1 if the square root doesn't exist.
 * It checks if the mid point between the start point and the end point
 * is the square root of n. If mid * mid is greater than n, it searhces
 * in the lower half. Else, it searches in the upper half. It does so
 * recursively until the square root is found or until it determines
 * that it doesn't exist.
 * @n: An integer
 * @s: Start point
 * @e: End point
 * Return: The square root of n, if found
 */
int _sqrt(int n, int s, int e)
{
	int mid;

	if (s > e)
		return (-1);

	mid = (s + e) / 2;

	if (mid * mid == n)
		return (mid);
	else if (mid * mid > n)
		return _sqrt(n, s, mid - 1);
	else
		return _sqrt(n, mid + 1, e);
}
/**
 * _sqrt_recursion - Finds the natural square root of a number
 * @n: An integer
 * Return: The natural square root of n
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return _sqrt(n, 0, n);
}
