#include "sort.h"
/**
 *  cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *  order using the Cocktail shaker sort algorithm
 * @list: double pointer listint_t
 */
void cocktail_sort_list(listint_t **list)
{
	int i = 0, size = 0, swapped;
	listint_t *head = *list, *tail, *temp;

	print_list(*list);
	while (head)
		size++, head = head->next;
	print_list(*list);
	do
	{
		head = *list;
		swapped = 0;
		while (i < size)
		{
			if (head->n < head->next->n)
			{
				temp = head;
				temp->next = head->next->next;
				temp->prev = head->next;
				head = head->next;
				head->next = temp;
				head->prev = head->prev->prev;
				swapped = 1;
			}
			head = head->next;
			i++;
		}
		tail = head;
		while (i > 0)
		{
			if (tail->n > tail->next->n)
			{
				temp = tail;
				temp->prev = tail->prev->prev;
				temp->next = tail->prev;
				tail = tail->prev;
				tail->prev = temp;
				tail->next = tail->next->next;
				swapped = 1;
			}
			tail = tail->prev;
			i--;
		}
	}while (swapped);
}
