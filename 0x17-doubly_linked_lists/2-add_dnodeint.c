#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: pointer to the head node of the list
 * @n: new node value
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

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
		new->n = n;
		new->prev = NULL;
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	return (new);
}
