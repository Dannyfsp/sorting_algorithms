#include "sort.h"

/**
 * insertion_sort_list - Entry point
 * Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: pointer to the list head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux;

	if (list == NULL || *list == NULL)
		return;

	aux = (*list)->next;

	while (aux != NULL)
	{
		while (aux->prev && aux->prev->n > aux->n)
		{
			aux->prev->next = aux->next;
			if (aux->next)
				aux->next->prev = aux->prev;
			aux->next = aux->prev;
			aux->prev = aux->next->prev;
			aux->next->prev = aux;

			if (aux->prev == NULL)
				*list = aux;
			else
				aux->prev->next = aux;
			print_list(*list);
		}
		aux = aux->next;
	}
}
