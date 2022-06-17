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
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t outer, inner, interval = 0;
	int value;

	while (interval < (size / 3))
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (outer = interval; outer < size; outer++)
		{
			value = array[outer];
			inner = outer;
			while (inner > interval - 1 && array[inner - interval] >= value)
			{
				array[inner] = array[inner - interval];
				inner = inner - interval;
			}
			array[inner] = value;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
