#include "lists.h"

/**
 * find_listint_loop - find start node loop
 * @head: root node
 * Return: address of the node where the loop star, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare, *tortoise;

	if (!head)
		return (NULL);

	hare = tortoise = head;

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = (hare->next)->next;

		if (hare == tortoise)
		{
			tortoise = head;

			while (tortoise && hare)
			{
				if (tortoise == hare)
					return (tortoise);

				tortoise = tortoise->next;
				hare = hare->next;
			}
		}
	}

	return (NULL);
}
