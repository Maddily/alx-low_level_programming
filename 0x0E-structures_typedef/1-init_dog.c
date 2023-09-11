#include "dog.h"

/**
 * init_dog - Initializes a variable of type struct dog
 * @d: A pointer to variable of type struct dog
 * @name: A pointer to a string which is a dog's name
 * @age: A dog's age
 * @owner: A pointer to a string which is the name of a dog's owner
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return (NULL);

	d->name = name;
	d->age = age;
	d->owner = owner;
}
