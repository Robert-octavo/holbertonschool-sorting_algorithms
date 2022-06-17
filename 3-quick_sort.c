#include "sort.h"
/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
int partition(int *array, size_t size, int left, int right);
void sort(int *array, size_t size, int left, int right);

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	sort(array, size, 0, size - 1);
}

/**
 * @brief
 *
 * @param array
 * @param size
 * @param left
 * @param right
 */

void sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = partition(array, size, left, right);
		sort(array, size, left, part - 1);
		sort(array, size, part + 1, right);
	}
}

/**
 * @brief
 *
 * @param array
 * @param size
 * @param left
 * @param right
 * @return int
 */
int partition(int *array, size_t size, int left, int right)
{
	int tmp, i;
	int j;

	i = left - 1;

    /*left*/
	for (j = left; j < right; j++)
	{
		if (array[j] < array[right])
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	/*right*/

	if (array[right] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}
