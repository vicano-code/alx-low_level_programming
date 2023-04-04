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
	listint_t *new, *current_node, *previous_node;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	current_node = *head;
	i = 0;
	while (current_node)
	{
		if (idx == i)
		{
			previous_node->next = new;
			new->next = current_node;
			break;
		}
		previous_node = current_node;
		current_node = current_node->next;
		i++;

		if (current_node == NULL)
		{
			free(new);
			return (NULL);
		}
	}
	return (new);
}
