#include "sort.h"

/**
 * counting_sort - sorts array of int using counting sort algo.
 * @array: Array to be sorted.
 * @size: Size of array.
 *
 * Return: void.
 */
void counting_sort(int *array, size_t size)
{
	int i, top = 0, *count_array = NULL;
	int *output_array = malloc(sizeof(int) * size);

	if (!output_array)
		return;

	if (size <= 1)
	{
		free(output_array);
		return;
	}

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > top)
			top = array[i];
	}

	count_array = malloc(sizeof(int) * (top + 1));
	if (!count_array)
	{
		free(output_array);
		return;
	}

	for (i = 0; i <= top; i++)
		count_array[i] = 0;

	for (i = 0; i <= top; i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= top; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, top + 1);

	for (i = (int)size - 1; i >= 0; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];

	free(output_array);
	free(count_array);
}
