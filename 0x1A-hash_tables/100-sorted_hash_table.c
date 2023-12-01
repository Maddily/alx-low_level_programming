#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 *
 * @size: The size of the hash table
 *
 * Return: A pointer to the hash table
*/
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	/*Allocate memory for the hash table*/
	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	/*Allocate memory for the array of pointers to linked lists*/
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	/*Initialize the struct members*/
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds a new element to a hash table
 *
 * @ht: A pointer to a hash table
 * @key: A pointer to a key string
 * @value: A pointer to a value string associated with the key
 *
 * Return: 1 on success, 0 on failure
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *current, *new_node;

	/*Handle an empty hash table or a NULL key/value*/
	if (!ht || !key || *key == '\0' || !value)
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (0);

	/*If key doesn't exist (nothing is at that index), add it*/
	if (!ht->array[index])
	{
		if (add_new_key(ht, key, value, index))
			return (1);
		else
			return (0);
	}
	/*If the key exists, update the value to which it's associated*/
	current = ht->shead;
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (!current->value)
				return (0);
			return (1);
		}
		current = current->snext;
	}
	/*If the key at the index != key, handle collision*/
	new_node = create_snode(key, value);
	if (!new_node)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	add_to_slist(ht, index);
	return (1);
}

/**
 * shash_table_get - Retrieve a value associated with a key
 *
 * @ht: A pointer to a hash table
 * @key: A pointer to a key string
 *
 * Return: A pointer to the value associated with the key,
 * or NULL if the key doesn't exist
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current;

	/*Handle an empty hash table or a NULL key or array*/
	if (!ht || !key || *key == '\0' || !ht->array)
		return (NULL);

	/*Traverse the sorted list and retrieve the value*/
	current = ht->shead;
	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);

		current = current->snext;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a hash table, sorted
 *
 * @ht: A pointer to a hash table
*/
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;

	/*If the list is empty*/
	if (!ht || !ht->shead)
		return;
	current = ht->shead;
	printf("{");
	/*Traverse the sorted list and print the key: value pairs*/
	while (current)
	{
		printf("'%s': '%s'", current->key, current->value);
		current = current->snext;
		if (current)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table, in reverse
 *
 * @ht: A pointer to a hash table
*/
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;

	/*If the list is empty*/
	if (!ht || !ht->shead)
		return;
	current = ht->stail;
	printf("{");
	/*Taverse the sorted list, in reverse, and print the key: value pairs*/
	while (current)
	{
		printf("'%s': '%s'", current->key, current->value);
		current = current->sprev;
		if (current)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a hash table
 *
 * @ht: A pointer to a hash table
*/
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current, *temp;

	/*If the hash table is empty*/
	if (!ht)
		return;

	/*Iterate over the hash table and free allocated memory*/
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

/**
 * add_new_key - Adds a new key (whose index
 * doesn't already exist) to a hash table
 *
 * @ht: A pointer to a hash table
 * @key: A pointer to a key string
 * @value: A pointer to a value string
 * @index: The index of the key
 *
 * Return: 1 on success, 0 on failure
*/
int add_new_key(shash_table_t *ht, const char *key, const char *value,
unsigned long int index)
{
	shash_node_t *current;

	ht->array[index] = create_snode(key, value);
	/*If creating a new node was a failure*/
	if (!ht->array[index])
		return (0);
	/*Handle the case when the table/list is empty*/
	if (!ht->shead || !ht->stail)
		ht->shead = ht->stail = ht->array[index];
	else
	{
		current = ht->shead;
		/*Traverse the sorted list and place the node where appropriate*/
		while (current)
		{
			if (key_index((unsigned char *)current->key, ht->size) > index)
			{
				/*If adding at the beginning of the list*/
				if (!current->sprev)
				{
					ht->array[index]->snext = current;
					current->sprev = ht->array[index];
					ht->shead = ht->array[index];
					return (1);
				}
				add_to_middle(current, ht, index);
				return (1);
			}
			current = current->snext;
		}
		/*Append to the end of the sorted list*/
		add_to_end(ht, index);
	}
	return (1);
}

/**
 * add_to_slist - Adds a new node to a sorted list
 *
 * @ht: A pointer to a hash table
 * @index: The index of the key
*/
void add_to_slist(shash_table_t *ht, unsigned long int index)
{
	shash_node_t *current;

	/*Handle the case when the table/list is empty*/
	if (!ht->shead || !ht)
		ht->shead = ht->stail = ht->array[index];
	else
	{
		current = ht->shead;
		/*Traverse the sorted list and place the node where appropriate*/
		while (current)
		{
			/**
			 * If the index of the current key in the list is greater
			 * than the index of the to-be-added key
			*/
			if (key_index((unsigned char *)current->key, ht->size) > index)
			{
				/*If adding at the beginning of the list*/
				if (!current->sprev)
				{
					ht->array[index]->snext = current;
					current->sprev = ht->array[index];
					ht->shead = ht->array[index];
					return;
				}
				add_to_middle(current, ht, index);
				return;
			}
			current = current->snext;
		}
		/*Append to the end of the sorted list*/
		add_to_end(ht, index);
	}
}

/**
 * add_to_middle - Adds a node in the middle of a list
 *
 * @current: A pointer to the current node in a sorted list
 * @ht: A pointer to a hash table
 * @index: The index of a key
*/
void add_to_middle(shash_node_t *current, shash_table_t *ht,
unsigned long int index)
{
	shash_node_t *temp;

	temp = current->sprev;
	current->sprev->snext = ht->array[index];
	ht->array[index]->snext = current;
	current->sprev = ht->array[index];
	ht->array[index]->sprev = temp;
}

/**
 * add_to_end - Appends a node to the end of a sorted list
 *
 * @ht: A pointer to a hash table
 * @index: The index of a key
*/
void add_to_end(shash_table_t *ht, unsigned long int index)
{
	ht->stail->snext = ht->array[index];
	ht->array[index]->sprev = ht->stail;
	ht->stail = ht->array[index];
}

/**
 * create_snode - Creates a new node
 *
 * @key: A pointer to a key
 * @value: A pointer to a value
 *
 * Return: A pointer to the new node, or NULL on failure
*/
shash_node_t *create_snode(const char *key, const char *value)
{
	shash_node_t *new_node;

	new_node = malloc(sizeof(shash_node_t));

	if (!new_node)
		return (NULL);

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	/*Initialize the pointers to nodes to NULL*/
	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;

	return (new_node);
}
