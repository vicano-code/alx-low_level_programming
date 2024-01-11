#include "lists.h"

/**
 * dlistint_len - number of elements in a linked dlistint_t list.
 * @h: the head node of the list
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}
