#include "dog.h"
#include <stdlib.h>

/**
 * find_length - Finds the length of a string
 * @s: A pointer to a string
 * Return: The string s's length
 */
int find_length(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * copy_string - Copies a string
 * @dest: A pointer to the copy
 * @src: A pointer to the original string
 * @len: The length of the original string
 * Return: A pointer to the copy
 */
char *copy_string(char *dest, char *src, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - Creates a new variable of type dog_t
 * @name: A pointer to a string which is a dog's name
 * @age: A dog's age
 * @owner: A pointer to a string which is the name of a dog's owner
 * Return: A pointer to a variable of type dog_t
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *dog_name, *owner_name;
	int name_len, owner_len;

	dog = malloc(sizeof(dog_t));

	if (dog == NULL)
		return (NULL);

	name_len = find_length(name);
	owner_len = find_length(owner);

	dog_name = malloc((name_len + 1) * sizeof(char));
	owner_name = malloc((owner_len + 1) * sizeof(char));

	if (dog_name == NULL || owner_name == NULL)
	{
		free(dog);
		free(dog_name);
		free(owner_name);
		return (NULL);
	}

	dog_name = copy_string(dog_name, name, name_len);
	owner_name = copy_string(owner_name, owner, owner_len);

	dog->name = dog_name;
	dog->age = age;
	dog->owner = owner_name;

	return (dog);
}
