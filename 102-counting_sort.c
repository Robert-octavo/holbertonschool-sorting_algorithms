#include "sort.h"
int _max_number(int *array, size_t size);
/**
 * counting_sort - function that sorts an array of
 * integers in ascending order using the Counting
 * sort algorithm
 * using the Selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *count = NULL;

	if (array == NULL || size <= 1)
		return;
    /*Find the maximun element*/
	max = _max_number(array, size);
	printf("%d", max);
    /*add the space that we need*/
	count = malloc(sizeof(size_t) * max + 1);
    /*Fill the array with 0*/
	for (i = 0; i <= max; i++)
		count[i] = 0;
    /*Store the count of each element at their respective index*/

}
/**
 * _max_number - Find the max number
 * @array:  array of integer
 * @size: array's size
 * Return: integer
 */
int _max_number(int *array, size_t size)
{
	size_t i;
	int max_number = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_number)
		max_number = array[i];
	}
	return (max_number);
}
