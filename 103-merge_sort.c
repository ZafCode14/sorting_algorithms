#include "sort.h"

/**
 * merge - Merge two subarrays into one sorted array
 * @array: The original array
 * @left: Pointer to the left subarray
 * @right: Pointer to the right subarray
 * @size_l: Size of the left subarray
 * @size_r: Size of the right subarray
 *
 * Return: void
 */
void merge(int *array, int *left, int *right, size_t size_l, size_t size_r)
{
	size_t i = 0, j = 0, k = 0;
	int *merged_array = malloc(sizeof(int) * (size_l + size_r));

	if (!merged_array)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_l);
	printf("[right]: ");
	print_array(right, size_r);

	while (i < size_l && j < size_r)
	{
		if (left[i] <= right[j])
		{
			merged_array[k] = left[i];
			i++;
		}
		else
		{
			merged_array[k] = right[j];
			j++;
		}
		k++;
	}
	for (; i < size_l; i++, k++)
		merged_array[k] = left[i];
	for (; j < size_r; j++, k++)
		merged_array[k] = right[j];
	for (k = 0; k < size_l + size_r; k++)
		array[k] = merged_array[k];

	printf("[Done]: ");
	print_array(array, size_l + size_r);
	free(merged_array);
}

/**
 * merge_sort - Sort an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t middle = size / 2;
		int *left = array;
		int *right = array + middle;
		size_t size_l = middle;
		size_t size_r = size - middle;

		merge_sort(left, size_l);
		merge_sort(right, size_r);

		merge(array, left, right, size_l, size_r);
	}
}
