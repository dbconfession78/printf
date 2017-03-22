#include "holberton.h"
/**
 * put_char - prints a char
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
int put_char(char *buffer, va_list list)
{
	int i = 0;

	buffer[i] = va_arg(list, int);
	return (1);
}
/**
 * put_string - prints a string
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
/* doesn't handle buffer overflow cases yet*/
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

	for (i = 0; i < 7; i++)
		buffer[i] = nil[i];

	return (7);
}
/**
 * put_percent - prints a char
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
int put_percent(char *buffer, va_list list)
{
	(void) list;
	buffer[0] = '%';
	return (1);
}
/**
 * put_int - prints an int
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
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
/**
 * put_unsigned - prints an unsigned int
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
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
