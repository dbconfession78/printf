#ifndef STRCPERCENT_H
#define STRCPERCENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "holberton.h"
#include <math.h>

int put_char(char *buffer, va_list list)
{
	int i = 0;

	buffer[i] = va_arg(list, int);
	return(1);
}

// doesn't handle buffer overflow cases yet
int put_string(char *buffer, va_list list)
{
	int i;
	char *str = va_arg(list, char*);
	char *nil = "(null)";

	if (str)
	{
		for (i = 0; str[i]; i++)
		{
			buffer[i] = str[i];
		}

		return (i);
	}

	for (i = 0; i < 6; i++)
		buffer[i] = nil[i];

	return(6);
}

int put_percent(char *buffer, va_list list)
{
	(void) list;
	buffer[0] = '%';
	return(1);
}

int put_int(char *buffer, va_list list)
{
	int original_num, num, ldgt, rdgt, exp;
	int i;

	original_num = va_arg(list, int);
	i = 0;
	rdgt = original_num % 10;
	original_num /= 10;
	num = original_num;
	exp = 1;

	if (rdgt < 0)
	{
		buffer[i++] = '-';
		rdgt *= -1;
		num *= -1;
		original_num *= -1;
	}
	if (num > 0)
	{
		while ((num / 10) != 0)
		{
			exp *= 10;
			num /= 10;
		}
		num = original_num;
		while (exp > 0)
		{
			ldgt = num / exp;
			buffer[i++] = (ldgt + '0');
			num -= ldgt * exp;
			exp /= 10;
		}
	}
	buffer[i++] = (rdgt + '0');
	return (i);
}

int put_unsigned(char *buffer, va_list list)
{
	unsigned int original_num, num, exp;
	int i, ldgt, rdgt;
	original_num = va_arg(list, int);
	i = 0;
	rdgt = original_num % 10;
	original_num /= 10;
	num = original_num;
	exp = 1;

	if (num > 0)
	{
		while ((num / 10) != 0)
		{
			exp *= 10;
			num /= 10;
		}
		num = original_num;
		while (exp > 0)
		{
			ldgt = num / exp;
			buffer[i++] = (ldgt + '0');
			num -= ldgt * exp;
			exp /= 10;
		}
	}
	buffer[i++] = (rdgt + '0');
	return (i);
}
int put_float(char *buffer, va_list list)
{
	(void) buffer; (void) list; /* remove these before working on func */
	return(1); // calc length to return
}

// returns warning when compiling
int put_hex_lower(char *buffer, va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char *hex = uitohex(num);
	unsigned int i;
	for (i = 0; i < (unsigned int) strlen(hex); i++)
	{
		buffer[i] = hex[i];
	}
	return(i);
}

// returns warning when compiling
int put_hex_upper(char *buffer, va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char *hex = uitohex(num);
	unsigned int i;
	for (i = 0; i < (unsigned int)strlen(hex); i++)
	{
		if (hex[i] >= 'a' && hex[i] <= 'f')
			hex[i] = hex[i] - 32;
	}
	for (i = 0; i < (unsigned int) strlen(hex); i++)
	{
		buffer[i] = (hex[i]);
	}
	return(i);

}

int put_binary(char *buffer, va_list list)
{
	int c, d, count;
	unsigned int n, n_copy;
	int binary_len = 0;
	count = 0;
	n = va_arg(list, int);
	n_copy = n;

	while((n_copy /= 2) > 0)
		binary_len++;

	for (c = binary_len; c >= 0; c--)
	{
		d = n >> c;

		if (d & 1)
			*(buffer + count) = 1 + '0';
		else
			*(buffer + count) = 0 + '0';
		count++;
	}
	*(buffer + count) = '\0';

	return(++binary_len);
}

int put_oct(char *buffer, va_list list)
{
	long int rem[50], i = 0, j = 0, length = 0;
	long int num = va_arg(list, long int);

	while(num > 0)
	{
		rem[i] = num % 8;
		num = num / 8;
		i++;
		length++;
	}
	for(i = length - 1;i >= 0; i--, j++)
	{
		buffer[j] = rem[i] + '0';
	}
	return(j);
}

int put_pointer_address(char *buffer, va_list list)
{
	char str[12], *strp;
	int i, j, remainder;
	size_t hex_num;

	i = j = 0;
	hex_num = (size_t)(va_arg(list, void *));
	while (hex_num != 0)
	{
		remainder = hex_num % 16;
		if (remainder > 9)
			str[i] = remainder + 87;
		else
			str[i] = remainder + 48;
		hex_num /= 16;
		i++;
	}
	str[i] = '\0';

	strp = malloc(sizeof(char) * i);
	if (strp == NULL)
		return (0);
	i--;
	for (j = 0; i >= 0; j++, i--)
	{
		strp[j] = str[i];
	}
	strp[j] = '\0';
	if (strp == NULL)
		return (0);
	i = j = 0;
	buffer[i++] = '0';
	buffer[i++]= 'x';
	while (strp[j] != '\0')
	{
		buffer[i++] = strp[j++];
	}
	free(strp);
	return (i);
}
#endif
