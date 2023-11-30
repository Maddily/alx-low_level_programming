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
	size_t flag = 1;

	if (!ht)
	{
		printf("{}\n");
	}
	else
	{
		i = 0;
		printf("{");
		while (i < ht->size)
		{
			if (ht->array[i])
			{
				current = ht->array[i];
				while (current)
				{
					printf("'%s': '%s'", current->key, current->value);
					flag = 0;
					current = current->next;
					if (current)
						printf(", ");
				}
			}
			if (ht->array[i + 1] && !flag)
				printf(", ");
			i++;
		}
		printf("}\n");
	}
}
