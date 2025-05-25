#include "lists.h"
/**
 * check_cycle - Checks if a singly linked list has a cycle.
 * @head: Pointer to the head of the list.
 * Uses Floyd's cycle-finding algorithm to detect a cycle.
 * Return: True if there’s a cycle, False otherwise.
 */
int check_cycle(listint_t *list)
{
    listint_t *slow = list;
    listint_t *fast = list;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}