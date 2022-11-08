#include "sort.h"

/**
 * swap_1 - swap current node
 * @current: current node
 * @after: next node
 * @list: original list
 */
void swap_1(listint_t *current, listint_t *after, listint_t **list)
{
	listint_t *before, *aux;

	if (current == NULL || after == NULL)
		return;

	before = current->prev;
	aux  = after->next;

	if (before != NULL)
		before->next = after;
	else
		*list = after;

	if (after != NULL)
		after->prev = current;

	current->next = aux;
	current->prev = after;
	after->next = current;
	after->prev = before;

	print_list(*list);
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *head = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;

		while (head->next != NULL)
		{
			if (head->n > head->next->n)
			{
				swap_1(head, head->next, list);
				swapped = 1;
				continue;
			}
			head = head->next;
		}

		swapped = 0;
		head = head->prev;

		while (head->prev != NULL)
		{
			if (head->n < head->prev->n)
			{
				swap_1(head->prev, head, list);
				swapped = 1;
				continue;
			}
			head = head->prev;
		}
		head = head->next;
	} while (swapped == 1);
}
