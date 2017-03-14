#include "holberton.h"
/**
 * _printf - prints all the input it is given
 * @format: pointer to input string
 * Return: buffer length
 */
int _printf(char const *format, ...)
{
	va_list list;
	char *buffer;
	char *temp_buffer;
	size_t buffer_mult = 1;
	int buffer_len = 0;
	int (*func)(char *buffer, va_list) = NULL;
	int skip;

	va_start(list, format);
	buffer = malloc(sizeof(char) * 1024);
	temp_buffer = malloc(sizeof(char) * 1024);
	reset_buffer(buffer, 1024);
	reset_buffer(temp_buffer, 1024);

	if (!format || (format[0] == '%' && strlen(format) == 1))
		return (-1);
	while (format && *format)
	{
		skip = 0;
		if (*format == '%')
		{
			while (*(format + 1) == ' ')
				format++;
			func = get_directive_function(*(format + 1));
			if (func)
			{
				buffer_len += func(buffer + buffer_len, list);
				format += 2; skip = 1;
			}
		}
		if (skip == 0)
		{
			getchar();
			if (buffer_len == 1022 * buffer_mult)
			{
				strcpy(temp_buffer, buffer);
				buffer_mult++;
				buffer = realloc(&buffer, 1024 * buffer_mult);
				reset_buffer(buffer,  1024 * buffer_mult);
				strcpy(buffer, temp_buffer);
				reset_buffer(temp_buffer, 1024);
			}

			buffer[buffer_len] = *format;
			format++; buffer_len++;
		}
	}
	write(1, buffer, buffer_len);

	va_end(list);
	return (buffer_len);
}
