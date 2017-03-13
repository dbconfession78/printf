#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "holberton.h"

/**
 * reset_buffer - sets all buffer elemnts to 0
 *
 * @buffer: buffer to reset
 *
 * Return: void
 */

void reset_buffer(char *buffer, int size)
{
	int i;
	for (i = 0; i < size; i++)
		buffer[i] = '\0';
}
