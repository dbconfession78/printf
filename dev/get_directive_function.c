#include "holberton.h"
#include "str_c_percent.h"

int  (*get_directive_function(char c))(char *s, va_list)
{
	int i;
	dir format[] = {
		{'c', put_char},
		{'s', put_string},
		{'%', put_percent},
		{'d', put_int},
		{'i', put_int},
		{'f', put_float},
		{'x', put_hex},
		{'b', put_binary},
		{'o', put_oct},
		{'\0', NULL}
	};

		for (i = 0; format[i].ch; i++)
		{
			if (c == format[i].ch)
				return (format[i].f);
		}
		return (NULL);
}
