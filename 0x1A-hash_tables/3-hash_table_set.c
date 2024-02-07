#include "hash_tables.h"


/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	char *key_dup;
	char *value_dup;
	hash_node_t *new_node;

	if (ht == NULL || (ht->array) == NULL || value ==  NULL)
		return (0);
	if (key == NULL || strlen(key) == 0)
		return (0);
	/* give the index of the key */
	idx = key_index((const unsigned char *)key, ht->size);

	key_dup = strdup(key);/*key duplicate*/
	if (!key_dup)
		return (0);
	value_dup = strdup(value); /*value duplicate*/
	if (!value_dup)
		return (0);
	/*check and update value of key if exists*/
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(key_dup);
		free(value_dup);
		return (0);
	}
	new_node->key = key_dup;
	new_node->value = value_dup;
	new_node->next = NULL;
	if (ht->array[idx] == NULL)
	{
		ht->array[idx] = new_node;
		return (1);
	}
	else
	{ /* collision: add new node at begining of list*/
		new_node->next = ht->array[idx];
		ht->array[idx] = new_node;
	}
	return (1);
}
