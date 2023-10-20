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
	int top = 0, i;
	int *count = NULL, *output;

	if (size < 2)
		return;

	output = malloc(sizeof(int) * size);

	if (!output)
		return;
	for (i = 0; i < (int)size; i++)
		top = array[i] > top ? array[i] : top;

	count = malloc(sizeof(int) * (top + 1));
	if (!count)
	{
		free(output);
		return;
	}
	for (i = 0; i <= top; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= top; i++)
		count_[i] += count[i - 1];

	print_array(count, top + 1);

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
