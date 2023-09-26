#include "lists.h"

/**
 * free_listint_safe - Frees a list.
 * @h: A pointer to the pointer pointing to the first node in the list.
 *
 * Return: The number of nodes in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp1, *tmp2;
	size_t count = 0;

	if (*h == NULL)
		return (0);

	tmp1 = tmp2 = *h;
	while (*h != NULL)
	{
		*h = (*h)->next;
		free(tmp1);
		tmp1 = tmp2 = *h;
		count++;
		if (tmp2 != NULL && tmp2->next != NULL)
		{
			tmp2 = tmp2->next->next;
			if (tmp1 == tmp2)
			{
				free(tmp1);
				free(tmp1->next);
				*h = NULL;
				count += 2;
				return (count);
			}
		}
	}
	*h = NULL;
	return (count);
}
