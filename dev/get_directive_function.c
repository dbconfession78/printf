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
		{'u', put_unsigned},
		{'f', put_float},
		{'x', put_hex_lower},
		{'X', put_hex_upper},
		{'b', put_binary},
		{'o', put_oct},
		{'p', put_pointer_address},
		{'\0', NULL}
	};

		for (i = 0; format[i].ch; i++)
		{
			if (c == format[i].ch)
				return (format[i].f);
		}
		return (NULL);
}
