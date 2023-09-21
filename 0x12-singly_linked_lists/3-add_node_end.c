#include "lists.h"
#include <string.h>

/**
 * _strlen - Finds the length of a string
 * @str: A pointer to a string
 * Return: The length of the string
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
/**
 * add_node_end - Adds a new node at the end of a list
 * @head: A pointer to the pointer pointing to the first node
 * @str: A pointer to a string
 * Return: A pointer to a new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *current;
	list_t *new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = _strlen(str);
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = new_node;
	}

	return (new_node);
}
