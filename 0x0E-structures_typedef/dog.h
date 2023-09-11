#ifndef HEADER_H

#define HEADER_H

/**
 * struct dog - Data about a dog
 * @name: A dog's name
 * @age: A dog's age
 * @owner: The name of a dog's owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);

#define NULL ((void *)0)

#endif
