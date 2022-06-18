#include "sort.h"
void swap(listint_t **pointer1, listint_t **pointer2, int n);

/**
 *  cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *  order using the Cocktail shaker sort algorithm
 * @list: double pointer listint_t
 */
void cocktail_sort_list(listint_t **list)
{
	int i, size = 0, swapped;
	listint_t *head = *list, *tail;

	while (head)
		size++, head = head->next;

	do {
		head = *list;
		i = 0, swapped = 0;
		while (i < size - 1)
		{
			if (head->n > head->next->n)
			{
				swap(&head, &head->next, 0);
				print_list(*list);
				swapped = 1;
			}
			head = head->next;
			i++;
		}
		tail = head, i = size - 1;
		while (i > 0)
		{
			if (tail->n < tail->prev->n)
			{
				swap(&tail->prev, &tail, 1);
				if (!tail->prev->prev)
					*list = tail->prev;
				print_list(*list);
				swapped = 1;
			}
			tail = tail->prev;
			i--;
		}
	} while (swapped);
}

/**
 * swap - swaps the elements of the list
 * @pointer1: first pointer input
 * @pointer2: second pointer input
 * @n: n is 0 for increase, n is 1 for decrease
 * Return: nothing
 */
void swap(listint_t **pointer1, listint_t **pointer2, int n)
{
	listint_t *aux = *pointer1, *tmp = *pointer2;

	aux->next = tmp->next, tmp->prev = aux->prev;

	if (tmp->next)
		tmp->next->prev = aux;

	if (aux->prev)
		aux->prev->next = tmp;

	aux->prev = tmp, tmp->next = aux;

	if (n == 0)
		*pointer1 = tmp;
	else
		*pointer2 = aux;
}

