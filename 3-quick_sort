#include <stdio.h>
#include "sort.h"

/* Function prototypes */

void quick_sort_recursive(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in @array
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * partition - Partition function for Quick sort using Lomuto scheme
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in @array
 *
 * Return: The index of the pivot element after partitioning
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int a = low - 1;
	int n, temp;

	for (n = low; n <= high - 1; n++)
	{
		if (array[n] <= pivot)
		{
			a++;
			if (a != n)
			{
				/* Swap the elements */
				temp = array[a];
				array[a] = array[n];
				array[n] = temp;

				/* Print the array after each swap */
				print_array(array, size);
			}
		}
	}

	if (a + 1 != high)
	{
		/* Swap the pivot element to its correct position */
		temp = array[a + 1];
		array[a + 1] = array[high];
		array[high] = temp;

		/* Print the array after the pivot is placed in its correct position */
		print_array(array, size);
	}

	return (a + 1);
}
