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
 * @size: The ending index of the partition.
 *
 * Return: The index of the pivot element after partitioning.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		if (array[i] > array[j])
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
}

/**
 * quicksort_hoare - sorts array of int using Quick sort.
 * @array: array to be sorted.
 * @low:  low index of array.
 * @high: high index of array.
 * @size: size of array.
 *
 * Return: void.
 */
void quicksort_hoare(int *array, size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t pvt = hoare_partition(array, low, high, size);

		if (pvt != 0)
			quicksort_hoare(array, low, pvt, size);
		quicksort_hoare(array, pvt + 1, high, size);
	}
}


/**
 * quick_sort_hoare - sorts array of int using quick sort algo.
 * @array: array to be sorted.
 * @size: size of array.
 *
 * Description: This function sorts an array of integers in ascending order by
 * selecting a pivot element and rearranging the other elements to ensure that
 * all elements smaller than the pivot are on the left, and all elements
 * greater are on the right.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size);
}
