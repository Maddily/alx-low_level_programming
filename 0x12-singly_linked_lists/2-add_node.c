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
 * add_node - Adds a new node at the beginning of a list
 * @head: A pointer to the pointer pointing to the first node
 * @str: A pointer to a string
 * Return: A pointer to a new node
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *tmp;

	if (*head == NULL)
	{
		*head = malloc(sizeof(list_t));
		if (*head == NULL)
			return (NULL);

		(*head)->str = strdup(str);
		(*head)->len = _strlen(str);
		(*head)->next = NULL;
	}
	else
	{
		tmp = malloc(sizeof(list_t));
		if (tmp == NULL)
			return (NULL);
		tmp->str = strdup(str);
		tmp->len = _strlen(str);
		tmp->next = *head;
		*head = tmp;
	}

	return (*head);
}
