#include "lists.h"
#include <stdlib.h>
/**
 * insert_nodeint_at_index -  inserts a new node at a given position
 * @head: pointr to the pointer to head node of the linked list
 * @idx: index of the list where the new node should be added
 * @n: new node data
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *current_node;
	listint_t *previous_node;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (*head == NULL && idx != 0)
		return (NULL);

	current_node = *head;
	i = 0;
	while (current_node != NULL)
	{
		if (idx == i && idx == 0)
		{
			previous_node = NULL;
			new->next = current_node;
			*head = new;
			return (new);
		}

		if (idx == i && idx != 0)
		{
			previous_node->next = new;
			new->next = current_node;
			return (new);
		}
		previous_node = current_node;
		current_node = current_node->next;
		i++;
	}

	return (NULL);
}
