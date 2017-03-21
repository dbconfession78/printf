#include "holberton.h"
/**
 * _strlen - returns the length of a string
 *
 *@s: character array to count
 *
 * Return: number of characters
 */

int _strlen(char *s)
{
	int i, c;

	i = 0;
	c = -1;
	while (c != 0)
	{
		c = s[i];
		if (c != 0)
		{
			i++;
		}
	}
	return (i);
}
/**
 * reset_buffer - sets all buffer elemnts to 0
 *
 * @buffer: buffer to reset
 *@size: the size of the buffer
 * Return: void
 */
void reset_buffer(char *buffer, int size)
{
	int i;

	for (i = 0; i < size; i++)
		buffer[i] = '\0';
}
/**
 * reverseStr - a function that reverses the string it is given
 * @string: input string
 * Return: reversed string
 */
char *reverseStr(char string[])
{
	char *result = malloc(strlen(string));
	unsigned int i;

	for (i = 0; i < strlen(string); i++)
	{
		result[i] = string[strlen(string) - 1 - i];
	}

	return (result);
}
/**
 * dectohex - returns the hex value of a decimal number
 * @r: input number
 * Return: hex char
 */
char dectohex(unsigned int r)
{
	if (r <= 9)
		return (r + '0');
	switch (r)
	{
	case 10:
		return ('a');
	case 11:
		return ('b');
	case 12:
		return ('c');
	case 13:
		return ('d');
	case 14:
		return ('e');
	case 15:
		return ('f');
	default:
		return ('\0');
	}
}
/**
 * uitohex - returns the hex value of an unsigned int
 * @num: input number
 * Return: hex char
 */
char *uitohex(unsigned int num)
{
	unsigned int r;
	char hex;
	char *result = malloc(sizeof(char) * 10);
	int i;

	if (num == 0)
		return ("0\0");
	for (i = 0; num != 0; i++)
	{
		r = num % 16;
		num /= 16;
		hex = dectohex(r);
		result[i] = hex;
	}
	result = reverseStr(result);
	result[i] = '\0';
	return (result);
}
