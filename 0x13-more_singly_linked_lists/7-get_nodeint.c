#include "lists.h"

/**
 * get_nodeint_at_index - get the nth node of a listint_t linked list
 * @head: pointr to the head node of the linked list
 * @index: index of node to get
 * Return: the node
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *current_node;

	i = 0;
	if (head == NULL)
		return (NULL);

	current_node = head;
	while (current_node->next != NULL)
	{
		if (index == i)
			return (current_node);

		current_node = current_node->next;
		i++;
	}

	return (NULL);
}
