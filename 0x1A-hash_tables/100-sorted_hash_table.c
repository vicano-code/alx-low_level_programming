#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table
 * @size: size of the array
 * Return: a pointer to the newly created hash table or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	shash_node_t **array;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	array = malloc(sizeof(*array) * size);
	if (array == NULL)
	{
		free(ht);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		array[i] = NULL;
		i++;
	}
	ht->size = size;
	ht->array = array;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * insert_into_sorted_list - insert node into list
 * @ht: sorted hash table
 * @node: node to insert
 * Return: 1 if success, 0 if fail
 */
int insert_into_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	/* empty table */
	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return (1);
	}
	if (strcmp(node->key, (ht->shead)->key) <= 0)/*insert at start*/
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else if (strcmp(node->key, (ht->stail)->key) > 0)/*insert at end*/
	{
		node->sprev = ht->stail;
		(ht->stail)->snext = node;
		ht->stail = node;
	}
	else /*insert in middle*/
	{
		tmp = ht->shead;
		while (tmp->snext && strcmp(node->key, tmp->key) > 0)
			tmp = tmp->snext;
		node->sprev = tmp;
		node->snext = tmp->snext;
		(tmp->snext)->sprev = node;
		tmp->snext = node;
	}
	return (1);
}

/**
 * create_and_add_node - create and add new node
 * @ht: hash table
 * @key: the key
 * @value: key value
 * @idx: hash table index to insert into
 * Return: 1-success, 0-fail
 */
int create_and_add_node(shash_table_t *ht, const char *key, const char *value,
			unsigned long int idx)
{
	char *key_dup, *value_dup;
	shash_node_t *new_node;

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	key_dup = strdup(key);
	if (key_dup == NULL)
	{
		free(new_node);
		return (0);
	}
	value_dup = strdup(value);
	if (value_dup == NULL)
	{
		free(new_node);
		free(key_dup);
		return (0);
	}
	new_node->key = key_dup;
	new_node->value = value_dup;
	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;
	if ((ht->array)[idx] == NULL)
		new_node->next = NULL;
	else
		new_node->next = (ht->array)[idx];
	(ht->array)[idx] = new_node;
	return (insert_into_sorted_list(ht, new_node));
}

/**
 * shash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	char *value_dup;
	shash_node_t *node = NULL;

	if (ht == NULL || (ht->array) == NULL || value ==  NULL)
		return (0);
	if (key == NULL || strlen(key) == 0)
		return (0);
	/* give the index of the key */
	idx = key_index((const unsigned char *)key, ht->size);
	node = (ht->array)[idx];
	/*check if node exists and update value*/
	while (node && (strcmp(key, node->key) != 0))
		node = node->next;
	if (node != NULL)
	{
		value_dup = strdup(value);
		if (!value_dup)
			return (0);
		if (node->value)
			free(node->value);
		node->value = value_dup;

		return (1);
	}
	return (create_and_add_node(ht, key, value, idx));
}

/**
 * shash_table_get - given key, retrieve value
 * @ht: hash table
 * @key: key
 * Return: value; or NULL if not 0found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *tmp;

	/* find index in hash table where key is */
	/* look through linked list to find matching key for value */

	if (!ht || !key)
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);

	tmp = (ht->array)[idx];
	while (tmp != NULL && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	else
		return (tmp->value);
}

/**
 * shash_table_print - prints the shash table
 * @ht: the hash table
 * Return: Nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char *delim = "";

	if (ht == NULL || ht->array == NULL)
		return;

	putchar('{');
	node = ht->shead;
	while (node)
	{
		printf("%s'%s': '%s'", delim, node->key, node->value);
		delim = ", ";
		node = node->snext;
	}
	puts("}");
}

/**
 * shash_table_print_rev - prints the shash table in reverse order
 * @ht: the hash table
 * Return: Nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char *delim = "";

	if (ht == NULL || ht->array == NULL)
		return;

	putchar('{');
	node = ht->stail;
	while (node)
	{
		printf("%s'%s': '%s'", delim, node->key, node->value);
		delim = ", ";
		node = node->sprev;
	}
	puts("}");
}

/**
 * shash_table_delete - deletes the shash table
 * @ht: the hash table
 * Return: Nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node, *tmp;

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
