#include "sort.h"

/**
 * bubble_sort - uses bubble sort to sort an array. prints sorted array
 * @array: ...
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 1;
	int changed = 1, temp;

	while (changed)
	{
		changed = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{ /* Swap */
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				changed = 1;
				print_array(array, size);
			}
		}
	}
}
