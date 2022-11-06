#include "sort.h"

/**
 * selection_sort - Entry point
 * Sorts an array of integers in ascending order
 * @array: pointer to the array of int to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
		if (min != i)
			print_array(array, size);
	}
}
