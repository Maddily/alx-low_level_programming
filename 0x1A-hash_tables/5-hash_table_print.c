#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 *
 * @ht: A pointer to a hash table
*/
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current;
	size_t flag = 0;

	if (!ht)
		return;
	i = 0;
	printf("{");
	while (i < ht->size)
	{
		if (ht->array[i])
		{
			if (flag)
				printf(", ");
			current = ht->array[i];
			while (current)
			{
				printf("'%s': '%s'", current->key, current->value);
				current = current->next;
				if (current)
					printf(", ");
			}
			flag = 1;
		}
		i++;
	}
	printf("}\n");
}
