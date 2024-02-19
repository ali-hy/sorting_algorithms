#include "sort.h"

/**
 * insertion_sort_list - sort a list using insertion sort
 * prints the updated list with every insertion
 * @list: ...
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list, *destination = NULL, *ptemp, *ntemp;

	if (curr == NULL || curr->next == NULL)
		return;
	curr = curr->next;
	while (curr != NULL)
	{
		destination = curr->prev;
		/* continue if curr is in correct position */
		if (destination->n <= curr->n)
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
	}
}
