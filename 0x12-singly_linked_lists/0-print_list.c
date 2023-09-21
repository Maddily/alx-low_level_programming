#include "lists.h"

/**
 * print_list - Prints all of the elements of a `list_t` list.
 * @h: A pointer to a `list_t` list (struct).
 * Return: The number of nodes
 */
size_t print_list(const list_t *h)
{
	int i = 0, j;
	size_t n = 0, len;
	const list_t *current = h;
	char null_str[] = "[0] (nil)";
	char len_str[10];

	while (current != NULL)
	{
		i = 0;
		if (current->str == NULL)
		{
			for (j = 0; null_str[j] != '\0'; j++)
				_putchar(null_str[j]);
		}
		else
		{
			len = current->len;
			while (len > 0)
			{
				len_str[i++] = (len % 10) + '0';
				len /= 10;
			}
			_putchar('[');
			for (i = i - 1; i >= 0; i--)
				_putchar(len_str[i]);
			_putchar(']');
			_putchar(' ');
			for (i = 0; (current->str)[i] != '\0'; i++)
				_putchar((current->str)[i]);
		}
		_putchar('\n');
		n++;
		current = current->next;
	}
	return (n);
}
