#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 *
 * @h: A pointer to a pointer pointing to the first node in the list
 * @idx: The position at which the node is to be inserted
 * @n: The data in the new node
 *
 * Return: A pointer to the new node
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current, *result;
	unsigned int i = 0;

	new_node = create_node(n);
	if (new_node == NULL)
		return (NULL);
	/*Handle empty list*/
	if (*h == NULL)
	{
		if (idx != 0)
			return (NULL);
		*h = new_node;
		return (new_node);
	}
	/*Handle inserting at the beginning*/
	if (idx == 0)
	{
		(*h)->prev = new_node;
		new_node->next = *h;
		*h = new_node;
		return (new_node);
	}
	/*Traverse the list*/
	current = *h;
	result = insert_node(current, new_node, idx, &i);
	if (result != NULL)
		return (result);
	/*Handle inserting at the end*/
	if (idx == i)
	{
		current = *h;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
		return (new_node);
	}
	if (new_node != NULL)
		free(new_node);
	return (NULL);
}
/**
 * create_node - Create a new node
 *
 * @n: The data to be inserted in the new node
 *
 * Return: The address of the new node
*/
dlistint_t *create_node(int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}
/**
 * insert_node - Inserts a node in a list at a given index
 *
 * @current: A pointer to a node
 * @new_node: A pointer to the new node
 * @idx: The index at which the new node is to be inserted
 * @i: A pointer to the index created for traversing
 *
 * Return: A pointer to the new node or NULL on failure
*/
dlistint_t *insert_node(dlistint_t *current,
	dlistint_t *new_node, unsigned int idx, unsigned int *i)
{
	dlistint_t *temp;

	while (current != NULL)
	{
		if (*i == idx)
		{
			temp = current->prev;
			current->prev = new_node;
			new_node->next = current;
			new_node->prev = temp;
			temp->next = new_node;
			return (new_node);
		}
		current = current->next;
		(*i)++;
	}

	return (NULL);
}
