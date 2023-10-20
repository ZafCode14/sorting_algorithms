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
	if (size < 2)
		return;

	int top = array[0];

	for (size_t i = 0; i < size; i++)
	{
		if (array[i] > top)
			top = array[i];
	}

	int *count = malloc(sizeof(int) * (top + 1));

	if (!count)
		return;

	for (int i = 0; i <= top; i++)
		count[i] = 0;
	for (size_t i = 0; i < size; i++)
		count[array[i]]++;
	for (int i = 1; i <= top; i++)
		count[i] += count[i - 1];

	int *output = malloc(sizeof(int) * size);

	if (!output)
	{
		free(count);
		return;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
