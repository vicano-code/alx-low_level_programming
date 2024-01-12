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

	if ((*head) == NULL)
		return (-1);

	current = *head;
	if (index == 0 && (*head)->next == NULL)
	{
		*head = NULL;
		free(current);
		return (1);
	}
	if (index == 0 && (*head)->next != NULL)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(current);
		return (1);
	}
	while (current)
	{
		if (idx == index)
		{
			previous->next = current->next;
			current->next->prev = previous;
			free(current);
			return (1);
		}
		previous = current;
		current = current->next;
		idx++;
	}
	free(current);
	return (-1);
}
