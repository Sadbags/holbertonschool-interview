#include "lists.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - Checks if singly linked list is palindrome
 * @head: Points to head of list
 * Return: 1 if palindrome and 0 if not
 */

int is_palindrome(listint_t **head)
{
	listint_t *tmp = *head;
	int array[2048], i = 0, j = 0, middle;

	if (head == NULL || (tmp != NULL && tmp->next == NULL))
		return (1);
	while (tmp != NULL)
	{
		array[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	i--, middle = i / 2;
	while (i >= middle && j <= middle)
	{
		if (array[j] != array[i])
			return (0);
		i--, j++;
	}
	return (1);
}