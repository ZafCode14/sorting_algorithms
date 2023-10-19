#include "sort.h"

/**
 * sift_down - Heapify a subarray rooted at index 'idx'
 * @array: Array to be sorted
 * @size: Size of the array
 * @idx: Index of the root of the subarray
 * @max_size: The maximum size of the heap
 *
 * Return: void
 */
void sift_down(int *array, size_t size, size_t idx, size_t max_size)
{
	size_t largest = idx;
	size_t left = 2 * idx + 1;
	size_t right = 2 * idx + 2;
	int temp;

	if (left < max_size && array[left] > array[largest])
		largest = left;

	if (right < max_size && array[right] > array[largest])
		largest = right;

	if (largest != idx)
	{
		temp = array[idx];
		array[idx] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		sift_down(array, size, largest, max_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, (size_t)i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, size, 0, (size_t)i);
	}
}
