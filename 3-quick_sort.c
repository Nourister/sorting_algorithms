#include "sort.h"

int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size);
void lomuto_quick_sort(int *array, ssize_t low, ssize_t high, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_quick_sort(array, 0, size - 1, size);
}

/**
 * lomuto_quick_sort - Implements the quicksort algorithm via Lomuto's method
 * @array: The array to be sorted
 * @low: The lower bound of the segment to sort
 * @high: The upper bound of the segment to sort
 * @size: The size of the array
 *
 * Return: No value returned.
 */

void lomuto_quick_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		ssize_t pivot = lomuto_partition(array, low, high, size);

		lomuto_quick_sort(array, low, pivot - 1, size);
		lomuto_quick_sort(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Implements Lomuto's partitioning scheme
 * @array: The array to be sorted
 * @low: The lower bound of the segment to sort
 * @high: The upper bound of the segment to sort
 * @size: The size of the array
 *
 * Return: The final position of the pivot
 */

int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		int temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
