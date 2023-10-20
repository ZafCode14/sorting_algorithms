#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using counting sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, i;
	int *count, *sorted_array;

	if (size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
		return;

	for (i = 0; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];

	count = calloc(sizeof(int), max + 1);
	if (!count)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = (int)size - 1; i >= 0; i--)
	{
		sorted_array[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(count);
}
