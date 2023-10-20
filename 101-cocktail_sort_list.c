#include "sort.h"

/**
 * swap - swap two nodes
 * @node1: pointer to node 1
 * @node2: pointer to node 2
 * @list: doubly linked list
 *
 * Return: void
 */
void swap(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *temp1 = node1->next;
	listint_t *temp2 = node2->prev;

	if (temp1 != NULL)
		temp1->prev = node2;
	if (temp2 != NULL)
		temp2->next = node1;

	node1->prev = temp2;
	node2->next = temp1;
	node1->next = node2;
	node2->prev = node1;

	if (*list == node2)
		*list = node1;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * @list: doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list, *first = NULL;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		while (check->next)
		{
			if (check->n > check->next->n)
			{
				swap(check->next, check, list);
				swapped = 1;
			}
			else
				check = check->next;
		}

		if (!swapped)
			break;

		swapped = 0;

		while (check->prev != first)
		{
			if (check->n < check->prev->n)
			{
				swap(check, check->prev, list);
				swapped = 1;
			}
			else
				check = check->prev;
		}
		first = check;
		check = *list;
	}
}
