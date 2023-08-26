#include "sort.h"

/**
 * lomuto_partition - Implements the Lomuto partitioning scheme.
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: Size of the array.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = (low - 1);
    int temp, j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                /* Swap array[i] and array[j] */
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }
    if (array[high] < array[i + 1])
    {
        /* Swap array[i + 1] and array[high] */
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quicksort_helper - Helper function to sort recursively.
 * @array: The array to be sorted.
 * @low: The starting index.
 * @high: The ending index.
 * @size: Size of the array.
 */
void quicksort_helper(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);

        quicksort_helper(array, low, pi - 1, size);
        quicksort_helper(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers using
 * the Quick sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_helper(array, 0, size - 1, size);
}

