#include "deck.h"

/**
 * compare_deck_nodes - Compare two deck nodes based on kind and value.
 * @a: First deck node
 * @b: Second deck node
 *
 * Return: Negative value if a < b, positive value if a > b, 0 if equal.
 */
int compare_deck_nodes(const void *a, const void *b)
{
	deck_node_t *node_a = *((deck_node_t **)a);
	deck_node_t *node_b = *((deck_node_t **)b);
	int kind_cmp = node_a->card->kind - node_b->card->kind;

	if (kind_cmp == 0)
	{
		const char *ranks[] = {
			"Ace", "2", "3", "4",
			"5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"
		};
		const char *rank_a = node_a->card->value;
		const char *rank_b = node_b->card->value;
		int rank_pos_a = -1;
		int rank_pos_b = -1;
		int i;

		for (i = 0; i < 13; i++)
		{
			if (strcmp(rank_a, ranks[i]) == 0)
				rank_pos_a = i;
			if (strcmp(rank_b, ranks[i]) == 0)
				rank_pos_b = i;
		}

		return (rank_pos_a - rank_pos_b);
	}
	return (kind_cmp);
}

/**
 * sort_deck - Sort a deck of cards in ascending order by kind and value.
 * @deck: Pointer to the head of the deck
 *
 * Return: void
 */
void sort_deck(deck_node_t **deck)
{
	int num_cards, i;
	deck_node_t *current;
	deck_node_t **deck_array;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	num_cards = 0;
	current = *deck;
	while (current != NULL)
	{
		num_cards++;
		current = current->next;
	}

	deck_array = (deck_node_t **)malloc(sizeof(deck_node_t *) * num_cards);
	current = *deck;
	for (i = 0; i < num_cards; i++)
	{
		deck_array[i] = current;
		current = current->next;
	}

	qsort(deck_array, num_cards, sizeof(deck_node_t *), compare_deck_nodes);

	for (i = 0; i < num_cards - 1; i++)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}
	deck_array[0]->prev = NULL;
	deck_array[num_cards - 1]->next = NULL;
	*deck = deck_array[0];

	free(deck_array);
}
