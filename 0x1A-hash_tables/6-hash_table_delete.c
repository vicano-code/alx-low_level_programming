#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node, *tmp;

	if (ht == NULL)
		return;
	if (ht->array == NULL)
	{
		free(ht);
		return;
	}
	i = 0;
	while (i < ht->size)
	{
		node = ht->array[i];
		while (node)
		{
			if (node->key)
				free(node->key);
			if (node->value)
				free(node->value);
			tmp = node->next;
			free(node);
			node = tmp;
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
