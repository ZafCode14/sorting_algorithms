#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Get the maximum element from an array
 * @array: The input array
 * @size: The size of the array
 *
 * Return: The maximum element in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * counting_sort_radix - Perform counting sort on an array
 *						based on the significant digit
 * @array: The input array
 * @size: The size of the array
 * @exp: The current significant digit to consider
 *
 * Return: void
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output;
	int count[10] = {0};
	int i;
	size_t j;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(output);
		return;
	}

	for (j = 0; j < size; j++)
		count[(array[j] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];

	print_array(array, size);
		free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix Sort
 * @array: The input array
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_radix(array, size, exp);
}

