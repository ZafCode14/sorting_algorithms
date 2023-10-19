#include "sort.h"
/**
 * swap_integers - Swap two integers in an array.
 * @a: A pointer to the first integer.
 * @b: A pointer to the second integer.
 *
 * Return: void
 */
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Recursively sort a bitonic sequence
 *					within an array of integers.
 * @array: An array of integers.
 * @size: The total size of the array.
 * @start: The starting index of the sequence to sort.
 * @seq_size: The size of the sequence to sort.
 * @ascending: The direction to sort in (1 for ascending, 0 for descending).
 *
 * Return: void
 */
void bitonic_merge(int *array, size_t size, size_t start,
		size_t seq_size, int ascending)
{
	size_t jump = seq_size / 2;
	size_t i;

	if (seq_size > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((ascending && array[i] > array[i + jump]) ||
					(!ascending && array[i] < array[i + jump]))
				swap_integers(&array[i], &array[i + jump]);
		}
		bitonic_merge(array, size, start, jump, ascending);
		bitonic_merge(array, size, start + jump, jump, ascending);
	}
}

/**
 * bitonic_sequence - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the block of the bitonic sequence.
 * @seq_size: The size of the block of the bitonic sequence.
 * @ascending: The direction to sort the bitonic sequence
 *				block (1 for ascending, 0 for descending).
 *
 * Return: void
 */
void bitonic_sequence(int *array, size_t size, size_t start,
		size_t seq_size, int ascending)
{
	size_t half = seq_size / 2;
	const char *sort_direction = ascending ? "UP" : "DOWN";

	if (seq_size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq_size, size, sort_direction);
		print_array(array + start, seq_size);

		bitonic_sequence(array, size, start, half, 1);
		bitonic_sequence(array, size, start + half, half, 0);
		bitonic_merge(array, size, start, seq_size, ascending);

		printf("Result [%lu/%lu] (%s):\n", seq_size, size, sort_direction);
		print_array(array + start, seq_size);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 *					using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, 1);
}
