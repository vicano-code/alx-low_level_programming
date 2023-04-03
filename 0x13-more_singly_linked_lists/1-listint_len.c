#include "lists.h"
#include <stddef.h>

/**
 * listint_len - number of elements in a linked listint_t list
 * @h: the listint_t list
 * Return: the number of elements
 */

size_t listint_len(const listint_t *h)
{
	size_t elem_count = 0;

	while (h)
	{
		if (h->n)
			elem_count++;

		h = h->next;
	}

	return (elem_count);
}
