#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "holberton.h"

/**
 *
 *
 *
 *
 * Return:
 */

char *reverseStr(char string[]) {
	char *result = malloc(strlen(string));
	int i;

	for(i=0; i<strlen(string); i++) {
		result[i] = string[strlen(string)-1-i];
	}

	return result;
}

char dectohex(unsigned int r)
{
	if (r >= 0 && r <= 9)
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

/*
int main(void)
{
	unsigned int num = 2147484671;
	char *hex = uitohex(num);
	printf("%s\n", hex);
	return (0);
}
*/
