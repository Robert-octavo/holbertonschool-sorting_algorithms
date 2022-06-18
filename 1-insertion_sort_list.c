#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked
 * list of integers in ascending order using the Insertion
 * sort algorithm
 * 
 * @list: pointer to the head of a doubly-linked list of integers
 */
listint_t *_swap(listint_t **current, listint_t **sorted);
void insertion_sort_list(listint_t **list)
{
    listint_t *current;
	listint_t *swap;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

    swap = *list;
	current = (*list)->next;

	while (current != NULL)
	{
		if (swap != NULL &&  current->n < swap->n)
		{

			current = _swap(&current, &swap);
			swap = current->prev;
			if (swap == NULL)
				*list = current;
			print_list(*list);

			while (swap != NULL && current->n < swap->n)
			{
				current = _swap(&current, &swap);
				swap = current->prev;
				if (swap == NULL)
					*list = current;
				print_list(*list);
			}
		}
		else
		{
			swap = current;
			current = swap->next;
		}
	}
}

listint_t *_swap(listint_t **current, listint_t **sawp)
{
	listint_t *tmp;

	tmp = (*current)->next;
	if (*sawp != NULL)
		(*sawp)->next = tmp;
	if (tmp != NULL)
	{
		tmp->prev = *sawp;
	}
	if (*current != NULL)
    {
        (*current)->next = *sawp;
		(*current)->prev = (*sawp)->prev;
    }
	if ((*sawp)->prev != NULL)
		(*sawp)->prev->next = *current;
	((*sawp)->prev) = *current;

	return (*current);
}