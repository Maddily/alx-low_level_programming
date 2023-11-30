#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 *
 * @size: The size of the table
 *
 * Return: A pointer to the hash table, or NULL on failure
*/
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *my_table;
	unsigned long int i;

	my_table = malloc(sizeof(hash_table_t));

	if (!my_table)
		return (NULL);

	my_table->array = calloc(size, sizeof(hash_node_t *));

	if (!my_table->array)
	{
		free(my_table);
		return (NULL);
	}

	my_table->size = size;

	return (my_table);
}
