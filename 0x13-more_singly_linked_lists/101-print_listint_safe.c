#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * check_loop - checks if loop exist in linked list
 * @head: pointer to list head node
 * Return: 0 if no loop, 1 if loop exist
 */

int check_loop(const listint_t *head)
{
	const listint_t *fast, *slow;

	fast = slow = head;
	while (fast != NULL && slow != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
			return (1);
	}
	return (0);
}

/**
 * node_count_before_loop - count num of nodes before loop
 * @head: pointr to had node of list
 * Return: node count
 */

int node_count_before_loop(const listint_t *head)
{
	const listint_t *fast, *slow;
	int count = 0;

	fast = slow = head;
	while (fast != NULL &&  slow != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		count++;
		if (fast == slow)
		{
			fast = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
				count++;
			}
			return (count);
		}
	}
	return (0);
}

/**
 * print_listint_safe - prints a listint_t linked list(safe version)
 * @head: pointer to the list
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t num_nodes = 0;
	int i = 0, checkloop, node_count;

	if (head == NULL)
		exit(98);

	checkloop = check_loop(head);
	if (checkloop == 1)
	{
		node_count = node_count_before_loop(head);
		while (i < node_count)
		{
			printf("[%p] %i\n", (void *)head, head->n);
			num_nodes++;
			head = head->next;
			i++;
		}
	}
	else
	{
		while (head)
		{
			printf("[%p] %i\n", (void *)head, head->n);
			num_nodes++;
			head = head->next;
		}
	}
	return (num_nodes);
}
