#include "sort.h"
#include <unistd.h>

/**
 * partition - resolves one partition in quick sort
 * @arr: array to sort
 * @low: ...
 * @high: ...
 * @size: size of array
 * Return: center of partitions
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high], temp;
	int i = (low - 1), j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	print_array(arr, size);

	return (i + 1);
}

/**
 * quick_sort_helper - sort array using quicksort (Lomuto partioning)
 * @array: ...
 * @low: start of partition
 * @high: end of partitions
 * @size: size of array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (high <= low)
		return;

	/* printf("low: %d, high %d\n", low, high) ;*/

	pivot = partition(array, low, high, size);

	quick_sort_helper(array, low, pivot - 1, size);
	quick_sort_helper(array, pivot + 1, high, size);
}

/**
 * quick_sort - sort array using quicksort (Lomuto partioning)
 * @array: ...
 * @size: ...
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}
