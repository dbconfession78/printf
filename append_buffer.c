#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "holberton.h"

/**
 * append_buffer - adds list argument to buffer
 *
 * @p_buff: buffer pointer
 * @str: string to add to buffer
 *
 * Return: void
 */

void append_buffer(char *dest, char *source, int append_index)
{
	int i, j = append_index;
//	printf("dest: %s\nsource: %s\nappend_index: %d\n", dest, source, append_index);
	for (i = 0; source[i] != '\0'; i++, j++)
	{


		dest[j] = source[i];

	}
}
