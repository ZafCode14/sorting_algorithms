#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the list.
 * @left: Pointer to the left node to be swapped.
 * @right: Pointer to the right node to be swapped.
 *
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	right->prev = left->prev;
	left->prev = right;
	left->next = right->next;
	right->next = left;
	if (left->next)
		left->next->prev = left;
	if (right->next)
		right->next->prev = right;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of
 *						integers in ascending order
 * using the Cocktail Shaker Sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 *
 * Reutrn: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;
	do {
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		current = current->prev;
		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				if (!current->prev)
					*list = current;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	} while (swapped);
}
