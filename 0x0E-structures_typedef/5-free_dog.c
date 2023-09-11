#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees previously allocated memory
 * @d: A pointer to a variable of type dog_t
 */
void free_dog(dog_t *d)
{
	free(d->name);
	free(d->owner);
	free(d);
}
