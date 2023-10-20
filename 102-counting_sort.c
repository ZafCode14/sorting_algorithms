#include "sort.h"

/**
  * counting_sort - A function that sorts an array
  *					using counting sort algorithm.
  * @array: The array to sort.
  * @size: The length of the array.
  *
  * Return: void
  */
void counting_sort(int *array, size_t size)
{
	unsigned int i = 1;
	int *count_array = NULL, max_val = 0, j = 0;

	if (array == NULL || size < 2)
		return;

	max_val = array[0];
	for (; i < size; i++)
		if (array[i] > max_val)
			max_val = array[i];
	count_array = malloc(sizeof(int) * (max_val + 1));
	if (count_array == NULL)
		return;
	for (j = 0; j <= max_val; j++)
		count_array[j] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]] += 1;
	for (j = 0; j < max_val; j++)
	{
		count_array[j + 1] += count_array[j];
		printf("%d, ", count_array[j]);
	}
	count_array[j + 1] += count_array[j];
	printf("%d\n", count_array[j + 1]);
	for (i = 0; i < size; i++)
	{
		j = count_array[array[i]] - 1;
		if (array[i] != array[j])
		{
			max_val = array[i];
			array[i] = array[j];
			array[j] = max_val;
		}
	}
	free(count_array);
}
