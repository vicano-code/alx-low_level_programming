#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: pointer to head node of the list
 * @index: node index to return
 * Return: nth node of list or NULL if not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (i <= index)
	{
		if (i == index)
		{
			return (head);
		}
		if (head == NULL && i < index)
			return (NULL);
		head = head->next;
		i++;
	}
	return (NULL);
}
