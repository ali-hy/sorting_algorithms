#include "sort.h"

/**
 * insertion_sort_list - sort a list using insertion sort
 * @list: ...
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list, *destination = NULL, *ptemp, *ntemp;

	while (curr != NULL)
	{
		/* find destination */
		destination = curr->prev;
		while (destination && curr->n < destination->n)
			destination = destination->prev;
		/* continue if curr is in correct position */
		if (destination == curr->prev)
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
		curr->prev = destination;

		/* handle destination == NULL */
		if (destination == NULL)
		{
			curr->prev = NULL;
			curr->next = *list;
			*list = curr;
			continue;
		}

		/* place curr in new position */
		curr->next = destination->next;
		curr->next->prev = curr;
		curr->prev = destination;
		destination->next = curr;
		print_list(*list);
		curr = curr->next;
	}
}
