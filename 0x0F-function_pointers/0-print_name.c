#include "function_pointers.h"

/**
 * print_name - Prints a name
 * @name: A pointer to a string
 * @f: A pointer to a function
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
