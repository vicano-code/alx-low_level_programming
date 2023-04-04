#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - delete node at index of a listint_t linked list
 * @head: pointer to the pointer to the head node
 * @index: index of node to delete
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *current, *previous;

	if (*head == NULL)
		return (-1);

	current = *head;
	if (index == 0)
		*head = current->next;
	else
	{
		i = 0;
		while (current)
		{
			if (index == i)
			{
				previous->next = current->next;
				break;
			}
			previous = current;
			current = current->next;
			i++;
		}
	}

	free(current);
	return (1);
}
