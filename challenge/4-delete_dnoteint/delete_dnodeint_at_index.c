#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the pointer to the first element of the list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;

	for (i = 0; i < index && node != NULL; i++)
		node = node->next;

	if (node == NULL) /* index out of range */
		return (-1);

	/* If deleting the head node */
	if (node->prev == NULL)
	{
		*head = node->next;
		if (node->next != NULL)
			node->next->prev = NULL;
	}
	else
	{
		node->prev->next = node->next;
		if (node->next != NULL)
			node->next->prev = node->prev;
	}

	free(node);
	return (1);
}
