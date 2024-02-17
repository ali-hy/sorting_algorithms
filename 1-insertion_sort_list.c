#include "sort.h"

/**
 * insertion_sort_list - sort a list using insertion sort
 * prints the updated list with every insertion
 * @list: ...
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list, *destination = NULL, *ptemp, *ntemp;
	int printed = 0;

	while (curr != NULL)
	{
		destination = curr->prev;
		/* continue if curr is in correct position */
		if (destination == NULL || destination->n <= curr->n)
		{
			curr = curr->next;
			continue;
		}
		/* remove curr from its position */
		ptemp = curr->prev;
		ntemp = curr->next;
		if (ptemp)
			ptemp->next = ntemp;
		if (ntemp)
			ntemp->prev = ptemp;

		/* place curr in new position */
		curr->next = destination;
		curr->prev = destination->prev;
		if (curr->next)
			curr->next->prev = curr;
		if (curr->prev)
			curr->prev->next = curr;
		else
			*list = curr;
		print_list(*list);
		printed = 1;
	}
	if (!printed)
		print_list(*list);
}
