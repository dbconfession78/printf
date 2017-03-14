#include "holberton.h"

/**
 * expand_buffer - 
 *
 *
 *
 * Return:
 */

void realloc_buffer(char *buffer, int *ptr_buffer_len)
{
	char *temp_buffer;

	temp_buffer = malloc(sizeof(char) * *ptr_buffer_len);
	reset_buffer(temp_buffer, *ptr_buffer_len);
	strcpy(temp_buffer, buffer);

	buffer = realloc(&buffer, (*ptr_buffer_len * 2));
	reset_buffer(buffer, MAX_BYTES * strlen(buffer));
	strcpy(buffer, temp_buffer);
	free(temp_buffer);
}
