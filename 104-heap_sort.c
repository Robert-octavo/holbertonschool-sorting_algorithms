#include "sort.h"
void _swap(int *a, int *b);
void heapify(int *array, size_t n, size_t i);
/**
 * _swap - Function to swap the the position of two elements
 * @a: Puntero
 * @b: Puntero
 */

void _swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * heapify - g
 *
 * @array: d
 * @n: d
 * @i: d
 */
void heapify(int *array, size_t n, size_t i)
{
	/*Find largest among root, left child and right child*/
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	/*Swap and continue heapifying if root is not largest*/
	if (largest != i)
	{
		_swap(&array[i], &array[largest]);
		print_array(array, n);
		heapify(array, n, largest);
	}
}

/**
 * heap_sort - function that sorts an array of integers in
 * ascending order using the Heap sort algorithm
 * You must implement the sift-down heap sort algorithm
 * @array: array of ints to sort
 * @size: size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size <= 1)
		return;

    /*Build max heap*/
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

    /*Heap Sort*/
	for (i = size - 1; i >= 0; i--)
	{
		_swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		/*Heapify root element to get highest element at root again*/
		heapify(array, i, 0);
	}
}
