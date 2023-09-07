#include <stdlib.h>
#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: A pointer to the previously allocated memory
 * @old_size: The number of bytes allocated for ptr
 * @new_size: The number of bytes of the new memory block
 * Return: A pointer to the newly allocated block of memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	unsigned int i;

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);

		if (new_ptr == NULL)
			return (NULL);

		return (new_ptr);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	if (new_size > old_size)
		for (i = 0; i < old_size; i++)
			new_ptr[i] = ((char *)ptr)[i];
	else
		for (i = 0; i < new_size; i++)
			new_ptr[i] = ((char *)ptr)[i];

	free(ptr);

	return (new_ptr);
}
