#ifndef STRCPERCENT_H
#define STRCPERCENT_H
#include "holberton.h"
int put_char(char *buffer, va_list list)
{
	int i = 0;

	buffer[i] = va_arg(list, int);
	return(1);
}

int put_string(char *buffer, va_list list)
{
	int i;
	char *str = va_arg(list, char*);
	char *nil = "(nil)";
	if (str)
	{
		for (i = 0; i < _strlen(str); i++)
			buffer[i] = str[i];
		return (i);
	}

	for (i = 0; i < 6; i++)
		buffer[i] = nil[i];

	return(6);
}

int put_percent(char *buffer, va_list list)
{
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

int put_float(char *buffer, va_list list)
{

	return(1); // calc length to return
}

int put_hex(char *buffer, va_list list)
{

	return(1); // calc length to return
}

int put_binary(char *buffer, va_list list)
{

	return(1); // calc length to return
}

int put_oct(char *buffer, va_list list)
{

	return(1); //calc length to return
}
#endif
