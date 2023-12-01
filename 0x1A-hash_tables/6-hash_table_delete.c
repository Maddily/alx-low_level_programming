#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 *
 * @ht: A pointer to a hash table
*/
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current, *temp;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current)
		{
			temp = current;
			free(current->key);
			free(current->value);
			current = current->next;
			free(temp);
		}
	}
	free(ht->array);
	free(ht);
}
