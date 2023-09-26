#include "lists.h"

/**
 * find_listint_loop - Checks for loops in a list.
 * @head: A pointer to the first node in a list.
 *
 * Return: A pointer to the node where the loop starts,
 * or NULL if there's no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *t, *h;

	if (head == NULL)
		return (NULL);

	t = h = head;

	while (t && h && h->next)
	{
		t = t->next;
		h = h->next->next;
		if (t == h)
		{
			t = head;
			while (t != h)
			{
				t = t->next;
				h = h->next;
			}
			return (t);
		}
	}

	return (NULL);
}
