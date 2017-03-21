#include "holberton.h"
/**
 * get_directive_function - this function helps _printf.c decide
 * which function to use depending on the letter after the %
 * @c: input letter which represents a conversion specifier
 * Return: the function to be used ot NULL is no match is found
 */
int  (*get_directive_function(char c))(char *s, va_list)
{
	int i;
	dir format[] = {
		{'c', put_char},
		{'s', put_string},
		{'%', put_percent},
		{'d', put_int},
		{'i', put_int},
		{'u', put_unsigned},
		{'x', put_hex_lower},
		{'X', put_hex_upper},
		{'b', put_binary},
		{'o', put_oct},
		{'p', put_pointer_address},
		{'r', put_reverse},
		{'R', put_rot13},
		{'\0', NULL}
	};

		for (i = 0; format[i].ch; i++)
		{
			if (c == format[i].ch)
				return (format[i].f);
		}
		return (NULL);
}
