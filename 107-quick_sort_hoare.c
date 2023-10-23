#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * hoare_partition - Partitions an array using the Hoare partition scheme.
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array
 *
 * Return: The index of the pivot element after partitioning.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (j < i)
			return (j);
		if (array[i] > array[j])
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
}
/**
 * quicksort - Sorts an array of integers using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: void
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		quicksort(array, low, pivot, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers
 *					in ascending order using Quick sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
