#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to the head of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		while (current->prev && current->prev->n > current->n)
		{
			temp = current;
			if (current->next)
				current->next->prev = temp->prev;
			current->prev->next = temp->next;
			current = current->prev;
			temp->prev = temp->prev->prev;
			temp->next = current->next;
			current->next = temp;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;
			print_list(*list);
		}
		current = current->next;
	}
}
