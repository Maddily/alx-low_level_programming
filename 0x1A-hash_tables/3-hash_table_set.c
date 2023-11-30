#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to a hash table
 *
 * @ht: A pointer to a hash table
 * @key: A pointer to a key
 * @value: A pointer to a value
 *
 * Return: 1 on success, 0 on failure
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *head, *new_node;

	if (!ht || !key || !value)
		return (0);
	/*Get the index*/
	index = key_index((unsigned char *)key, ht->size);
	head = ht->array[index];
	/*If key doesn't exist*/
	if (head == NULL)
	{
		head = create_node(key, value);
		if (!head)
			return (0);
		ht->array[index] = head;
		return (1);
	}
	/*If the existing key == key, update the existing value*/
	while (head)
	{
		if (strcmp(head->key, key) == 0)
		{
			free(head->value);
			head->value = strdup(value);
			if (!head->value)
				return (0);
			return (1);
		}
		head = head->next;
	}
	/**
	* If the key != key, handle collision by
	* adding the new node at the head of the list
	*/
	new_node = create_node(key, value);
	if (!new_node)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}

/**
 * create_node - Creates a new node
 *
 * @key: A pointer to a key
 * @value: A pointer to a value
 *
 * Return: A pointer to the new node, or NULL on failure
*/
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));

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

	new_node->next = NULL;

	return (new_node);
}
