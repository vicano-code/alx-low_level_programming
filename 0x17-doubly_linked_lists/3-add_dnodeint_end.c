#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to the head node of the list
 * @n: node value to add
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *current;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return NULL;

	if ((*head) == NULL)
	{
		*head = new;
		new->n = n;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		current = *head;
		while (current)
		{
			if (current->next == NULL)
			{
				new->n = n;
				current->next = new;
				new->prev = *head;
				new->next = NULL;
			}
			current = current->next ;
		}
	}
	return (new);
}
