#include "holberton.h"
/**
 * put_reverse - prints a string in reverse
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
int put_reverse(char *buffer, va_list list)
{
	int len, i, j;
	char *str;

	i = j = 0;
	str = va_arg(list, char *);
	len = _strlen(str);

	for (i = (len - 1); i >= 0; i--, j++)
	{
		buffer[i] = str[j];
	}
	return (j);
}
/**
 * put_rot13 - prints a string in rot13
 * @buffer: input buffer
 * @list: input value
 * Return: buffer advancement
 */
int put_rot13(char *buffer, va_list list)
{
	char *rot;
	int i;
	int j;
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char l[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	rot = va_arg(list, char *);
	if (rot == NULL)
		return (0);
	for (i = 0; rot[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (rot[i] == l[j])
			{
				buffer[i] = rot13[j];
				break;
			}
			if (j == 52)
				buffer[i] = rot[i];
		}
	}
	return (i);
}
