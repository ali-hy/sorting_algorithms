#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

/**
 * test_insertion_sort_list - what do u want
 */
void test_insertion_sort_list(void)
{
	/* Array of test case sizes, represented as constants.*/
	const int test_case_sizes[] = {0, 1, 1, 2, 3, 5, 5, 5, 5, 4, 6, 7};
	int a1[] = {0},				/*Empty list*/
		a2[] = {42},			/*Single-element list*/
		a3[] = {42, 42},		/*Identical elements*/
		a4[] = {42, 21, 42},	/*Duplicate elements*/
		a5[] = {5, 4, 3, 2, 1}, /*Reversed order*/
		a6[] = {1, 2, 3, 4, 5}, /*Already sorted*/
		a7[] = {5, 1, 4, 2, 3}, /*Mixed order*/
		/*Additional test cases:*/
		a8[] = {-5, 2, 9, -1, 4},	   /*Negative numbers*/
		a9[] = {10000, 1, 0, -10000},  /*Large and small numbers*/
		a10[] = {1, 3, 2, 5, 4, 6},	   /*Even-sized list*/
		a11[] = {1, 3, 2, 5, 4, 6, 7}, /*Odd-sized list*/
			**test_cases = malloc(12 * sizeof(int *));
	int num_test_cases = 11;
	int i;
	listint_t *list = NULL;

	test_cases[1] = a1;
	test_cases[2] = a2;
	test_cases[3] = a3;
	test_cases[4] = a4;
	test_cases[5] = a5;
	test_cases[6] = a6;
	test_cases[7] = a7;
	test_cases[8] = a8;
	test_cases[9] = a9;
	test_cases[10] = a10;
	test_cases[11] = a11;

	for (i = 1; i <= num_test_cases; i++)
	{
		printf("Testcase #%d - ", i);
		list = create_listint(test_cases[i], test_case_sizes[i]);
		print_list(list);
		printf("\n");
		insertion_sort_list(&list);
		printf("\n");
		print_list(list);
		printf("\n");
	}
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	test_insertion_sort_list();

	return (0);
}
