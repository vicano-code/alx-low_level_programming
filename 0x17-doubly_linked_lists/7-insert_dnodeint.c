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

	if ((*h) == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	current = *h;
	while (i <= idx)
	{
		if (current == NULL && idx > i)
			return (NULL);
		if (i == idx)
		{
			new->n = n;
			new->prev = previous;
			new->next = current;
			current->prev = new;
			previous->next = new;
		}
		previous = current;
		current = current->next;
		i++;
	}
	return (new);
}
