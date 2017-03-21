#include "holberton.h"
/**
 * put_hex_lower - prints a hex number in lower case
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
int put_hex_lower(char *buffer, va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char *hex = uitohex(num);
	unsigned int i;

	for (i = 0; i < (unsigned int) strlen(hex); i++)
	{
		buffer[i] = hex[i];
	}
	return (i);
}
/**
 * put_hex_upper - prints a hex number in upper case
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
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
	return (i);

}
/**
 * put_binary - prints a number in binary
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
int put_binary(char *buffer, va_list list)
{
	int c, d, count;
	unsigned int n, n_copy;
	int binary_len = 0;

	count = 0;
	n = va_arg(list, int);
	n_copy = n;

	while ((n_copy /= 2) > 0)
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

	return (++binary_len);
}
/**
 * put_oct - prints a number in base 8
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
int put_oct(char *buffer, va_list list)
{
	long int rem[50], i = 0, j = 0, length = 0;
	long int num = va_arg(list, long int);
	if (num == 0)
	{
		buffer[0] = '0';
		return (1);
	}
	while (num > 0)
	{
		rem[i] = num % 8;
		num = num / 8;
		i++;
		length++;
	}
	for (i = length - 1; i >= 0; i--, j++)
	{
		buffer[j] = rem[i] + '0';
	}
	return (j);
}
/**
 * put_pointer_address - prints address of a pointer
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
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

	i = j = 0;
	buffer[i++] = '0';
	buffer[i++] = 'x';
	while (strp[j] != '\0')
	{
		buffer[i++] = strp[j++];
	}
	free(strp);
	return (i);
}
