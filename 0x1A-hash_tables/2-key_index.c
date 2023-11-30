#include "hash_tables.h"

/**
 * key_index - Returns the index of a given key
 *
 * @key: A pointer to a key
 * @size: The size of the hash table
 *
 * Return: The index of the key
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	hash = hash_djb2(key);

	return (hash % size);
}
