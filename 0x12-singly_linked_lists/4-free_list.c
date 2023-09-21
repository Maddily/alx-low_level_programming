#include "lists.h"

/**
 * free_list - Frees a linked list
 * @head: A pointer to the first node in the list
 */
void free_list(list_t *head)
{
	list_t *current;
	list_t *next;

	current = head;

	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
}
