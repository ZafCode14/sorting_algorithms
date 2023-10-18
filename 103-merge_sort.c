#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - merge two sorted subarrays.
 * @array: the main array.
 * @size: size of array.
 * @left: pointer to left subarray.
 * @right: pointer to right subarray.
 *
 * Return: void
 */
void merge(int *array, size_t size, int *left, int *right)
{
	int *tmp;
	size_t i = 0, j = 0, k = 0, size_left = size / 2;
	size_t size_right = size - size_left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[Right: ]");
	print_array(right, size_right);

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	while (i < size_left && j < size_right)
	{
		if (left[i] <= right[j])
			tmp[k++] = left[i++];
		else
			tmp[k++] = right[j++];
	}

	while (i < size_left)
		tmp[k++] = left[i++];
	while (j < size_right)
		tmp[k++] = right[j++];

	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	printf("[Done]: ");
	print_array(array, size);
	free(tmp);
}

/**
 * merge_sort - sorts array of int using merge sort algo.
 * @array: array to be sorted.
 * @size: size of array.
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *right, *left;
	size_t half = size / 2;

	if (size < 2 || array == NULL)
		return;

	left = array;
	right = array + half;

	merge_sort(left, half);
	merge_sort(right, size - half);

	merge(array, size, left, right);
}
