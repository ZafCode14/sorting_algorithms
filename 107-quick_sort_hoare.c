#include "sort.h"

/**
 * hoare_partition - Partiotions array using Hoare sheme.
 * @array: array to be partitioned.
 * @low: low index of partition.
 * @high: high index of partition.
 * @size: size of array.
 *
 * Return: Index of pivot element.
 */
size_t hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t l = low - 1, h = high + 1;
	int pvt = array[h];

	while (1)
	{
		do {
			l++;
		} while (array[l] < pvt);

		do {
			h--;
		} while (array[h] > pvt);

		if (l < h)
		{
			int tmp = array[l];

			array[l] = array[h];
			array[h] = tmp;
			print_array(array, size);
		}
		else
			return (h);
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
 * quick__sort_hoare - sorts array of int using quick sort algo.
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
