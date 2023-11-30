#include "hash_tables.h"

/**
 * hash_table_get - Retrieve a value associated with a key
 *
 * @ht: A pointer to a hash table
 * @key: A pointer to a key
 *
 * Return: A pointer to the value associated with the key,
 * or NULL if the key doesn't exist
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	if (!ht || !key || !ht->array)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);

	current = ht->array[index];

	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);

		current = current->next;
	}

	return (NULL);
}
