#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees previously allocated memory
 * @d: A pointer to a variable of type dog_t
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		if (d->name != NULL)
		{
			free(d->name);
			d->name = NULL;
		}

		if (d->owner != NULL)
		{
			free(d->owner);
			d->owner = NULL;
		}

		free(d);
	}
}
