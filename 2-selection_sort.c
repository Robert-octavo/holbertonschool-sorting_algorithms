#include "sort.h"
/**
 * _swap - function for swap two integers
 * @a: input pointer integer
 * @b: input pointer integer
 */
void _swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minor;
	int *array_cpy;

	for (i = 0; i < size - 1; i++)
	{
		minor = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minor])
			{
				minor = j;
			}
		}
		for (i = 0; i < size - 1; i++)
		{
			array_cpy[i] = array[i];
		}

		if (minor != i)
		{
			_swap(&array[i], &array[minor]);
		}
		for (i = 0; i < size - 1; i++)
		{
			if (array_cpy[i] != array[i])
			{
				print_array(array, size);
				break;
			}
		}
	}
}
