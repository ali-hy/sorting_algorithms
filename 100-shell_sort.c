#include "sort.h"

/**
 * swap - swaps two integers
 * @a: address of int a
 * @b: address of int b
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * get_interval - given a size, get the largest interval that can be used for
 * shell sort based on the knuth sequence
 * @size: size of array
 * Return: size of largest interval
 */
int get_interval(size_t size)
{
	int res = 1;
	int next = 3 + 1;

	while (next < (int)size)
	{
		res = next;
		next = 3 * next + 1;
	}

	return (res);
}

/**
 * knuth_prev - get previous value in knuth sequence
 * @curr: current value in knuth sequence
 * Return: previous value in knuth sequence
 */
int knuth_prev(int curr)
{
	return ((curr - 1) / 3);
}

/**
 * shell_sort - sort array using shell sort
 * @array: ...
 * @size: ...
 */
void shell_sort(int *array, size_t size)
{
	int interval = get_interval(size);
	size_t i, j, k;

	while (interval)
	{
		/* printf("interval: %d\n", interval); */
		for (i = 0; (int)i < interval; i++)
		{
			for (j = i + interval; j < size; j += interval)
			{
				k = j;
				/* printf("comparing a[%lu] and a[%lu]\n", k, k - interval); */
				while ((int)k >= interval && array[k] < array[k - interval])
				{
					/* printf("swapping a[%lu] and a[%lu] :D\n", k, k - interval); */
					swap(array + k, array + k - interval);
					k -= interval;
				}
			}
		}
		print_array(array, size);
		/* printf("-----------------------------------\n"); */
		interval = knuth_prev(interval);
	}
}
