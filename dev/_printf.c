#include "holberton.h"

int _printf(char const *format, ...)
{
	va_list list;
	char buffer[1024];
	int buffer_len = 0;
	int (*func)(char *buffer, va_list) = NULL;
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
    int len;
    int len2;
    unsigned int ui;
    void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
	return (0);
}
