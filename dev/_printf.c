#include "holberton.h"

int _printf(char const *format, ...)
{
	va_list list;
	char buffer[1024];
	int buffer_len = 0;
	int (*func)(char *buffer, va_list) = NULL;
	unsigned int i = 0;
	int skip;

	va_start(list, format);
	reset_buffer(buffer, 1024);

	while (format && *format)
	{
		skip = 0;
		if (*format == '%')
		{
			while(*(format + 1) == ' ')
				format++;
			func = get_directive_function(*(format + 1));
			if (func)
			{
				buffer_len += func(buffer + buffer_len, list);
				format+=2; skip = 1;
			}
		}
		if (skip == 0)
		{
			buffer[buffer_len] = *format;
			format++; buffer_len++;
		}
	}
	write(1, buffer, buffer_len);

	va_end(list);
	return(buffer_len);
}

int main(void)
{
	char *str = "Hello";
	_printf("%%%%%   %   %s WORLD!!\n", str);
	printf("%%%%%   %   %s WORLD!!\n", str);
	return (0);
}
