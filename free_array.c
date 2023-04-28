#include "main.h"

/**
 * free_array - frees an array
 * @array: array to be freed
 */

void free_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
