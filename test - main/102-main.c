#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    /*int array[] = {0, 0, 1, 10, 1, 1, 2, 2, 4, 5};*/
    int array[] = {4, 100, 1, 20, 9, 80, 3, 24, 56, 50, 2, 10, 40};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    counting_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
