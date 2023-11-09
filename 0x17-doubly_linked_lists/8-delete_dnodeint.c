#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a given index
 *
 * @head: A pointer to the pointer pointing to the first node in the list
 * @index: The index at which the node to be deleted is located
 *
 * Return: 1 on success, -1 on failure
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i = 0;

	/*If list is empty*/
	if (*head == NULL)
		return (-1);

	current = *head;
	/*Deleting the first node*/
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}
	/*Traverse the list*/
	while (current != NULL)
	{
		if (i == index)
		{
			/*Deleting the last node*/
			if (current->next == NULL)
			{
				temp = current->prev;
				temp->next = NULL;
				free(current);
				return (1);
			}
			/*Deleting the node at the index*/
			current->prev->next = current->next;
			current->next->prev = current->prev;
			free(current);
			return (1);
		}
		current = current->next;
		i++;
	}
	return (-1);
}
