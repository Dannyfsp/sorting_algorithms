#include "sort.h"

/**
 * shell_sort - Entry point
 * Sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * using the knuth sequence
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, tmp, interval = 0;
	int valueToInsert;

	if (array == NULL || size < 2)
		return;

	while (interval <= size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			valueToInsert = array[i];
			j = i;
			while (j > interval - 1 && array[j - interval] >= valueToInsert)
			{
				tmp = array[j - interval];
				array[j - interval] = array[j];
				array[j] = tmp;
				j -= interval;
			}
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
