#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer of the head node of list
 * @idx: index to insert node
 * @n: node value to insert
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *previous, *new;
	unsigned int i = 0;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*h == NULL && idx == 0) /* insert in empty list */
	{
		*h = new;
		new->prev = NULL;
		new->next = NULL;
		return (new);
	}
	current = *h;
	if (idx == 0) /*non-empty list-insert at start of list */
	{
		*h = new;
		new->next = current;
		return (new);
	}
	while (current)
	{
		if (i == idx) /* insert within list index */
		{
			new->prev = previous;
			new->next = current;
			current->prev = new;
			previous->next = new;
		}
		else if (current->next == NULL && (i + 1) == idx)
		{
			current->next = new;
			new->prev = current;
			new->next = NULL;
			break;
		}
		previous = current;
		current = current->next;
		i++;
	}
	return (new);
}
