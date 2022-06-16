#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int swap;

	if (array == NULL || size <= 1)
		return;
/*Loop the entire array*/
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
		/*
		*compare if the current position has a bigger value
		*than the next position
		*/
			if (array[j] > array[j + 1])
			{
			/*swap the values*/
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, size);
			}
		}
	}

}
