#include "lists.h"

/**
 * sum_listint - sum of all the data(n) of a listint_t linked list
 * @head: pointr to the head node of the linked list
 * Return: the sum or 0 if empty
 */

int sum_listint(listint_t *head)
{
	int sum;
	listint_t *current_node;

	if (head == NULL)
		return (0);

	sum = 0;
	current_node = head;
	while (current_node != NULL)
	{
		sum += current_node->n;
		current_node = current_node->next;
	}

	return (sum);
}
