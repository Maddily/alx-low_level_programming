#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a list
 *
 * @head: A pointer to a pointer pointing to the first node in the list
 * @n: The data to be inserted in the new node
 *
 * Return: The address of the new node
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *temp;

	new_node = create_node(n);
	if (new_node == NULL)
		return (NULL);

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	temp = *head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}
/**
 * create_node - Create a new node
 *
 * @n: The data to be inserted in the new node
 *
 * Return: The address of the new node
*/
dlistint_t *create_node(const int n)
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
