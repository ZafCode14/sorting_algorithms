#include "sort.h"

/**
 * counting_sort - Sorts an array using counting sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max_val = array[0];
	size_t i, j;
	int *count_array, *output;

	if (array == NULL || size < 2)
		return;
	for (i = 1; i < size; i++)
		if (array[i] > max_val)
			max_val = array[i];
	count_array = malloc(sizeof(int) * (max_val + 1));
	if (count_array == NULL)
		return;
	for (j = 0; j <= (size_t)max_val; j++)
		count_array[j] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]] += 1;
	for (j = 0; j < (size_t)max_val; j++)
	{
		count_array[j + 1] += count_array[j];
		printf("%d, ", count_array[j]);
	}
	count_array[j + 1] += count_array[j];
	printf("%d\n", count_array[j + 1]);
	output = malloc(sizeof(int) * size);
	for (i = size - 1; i < size; i--)
	{
		j = count_array[array[i]] - 1;
		output[j] = array[i];
		count_array[array[i]] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(count_array);
}
