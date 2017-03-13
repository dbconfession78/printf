#include "holberton.h"

int _printf(char const *format, ...)
{
	va_list list;
	char buffer[1024];
	char type;
	int buffer_len = 0, (*func)(char *buffer, va_list) = NULL;
	va_start(list, format);
	reset_buffer(buffer, 1024);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++; //skip first %
			type = *format; // set type to s,c etc.
			func = get_directive_function(type); // get matching func for type
			buffer_len+=func(buffer + buffer_len, list); // set next index to write in buffer
			format++; // advance input's pointer after handling format
		}
		else
		{
			buffer[buffer_len] = *format;
			buffer_len++; format++;
		}
	}
	write(1, buffer, buffer_len);

	va_end(list);
	return(0);
}

int main(void)
{
	char *str = "Hello";
	_printf("%%%%% %s_ _ _ WORLD!!!\n", str);
	return (0);
}
