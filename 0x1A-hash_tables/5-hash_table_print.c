#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node;
	char *delim = "";

	if (ht == NULL || ht->array == NULL)
		return;
	
	i = 0;
	putchar('{');
	while (i < ht->size)
	{
		node = ht->array[i];
		while (node)
		{
			printf("%s'%s': '%s'", delim, node->key, node->value);
			delim = ", ";
			node = node->next;
		}
		i++;
	}
	puts("}");
}
