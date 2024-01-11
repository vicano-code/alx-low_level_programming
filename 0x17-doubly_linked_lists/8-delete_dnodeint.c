#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index
 * of a dlistint_t linked list
 * @head: pointer to the head node of the list
 * @index: node index to delete
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *previous;
	unsigned int idx = 0;

	if ((*head) == NULL || head == NULL)
		return (-1);
	current = *head;
	while (idx <= index)
	{
		if (current == NULL && idx < index)
			return (-1);
		if (idx == index)
		{
			if (index == 0)
			{
				*head = current->next;
				if (current != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				previous->next = current->next;
				current->next->prev = previous;
			}
		}
		previous = current;
		current = current->next;
		idx++;
	}
	return (1);
}
