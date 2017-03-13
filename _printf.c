#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "holberton.h"

/**
 * _printf - recieves standard input stream and writes to standard output stream
 * @format: character string that handles the 'c' 's' and '%' directives
 * Return: number of characters printed
 */


int _printf(const char *format, ...)
{
	char buffer[1024];
	char *p_buff;
	va_list list;
	int char_count = 0, i = 0;

	va_start(list, format);
	reset_buffer(buffer, 1024);

	printf("%s\n", buffer);

	while (*format)
	{
		if (*format != '%')
		{
			buffer[i] = *format;
			i++; format++;
		}
		else
		{
			format++;
			// handle second %
			if (*format == '%')
			{
				format++;
				if(*format == '%')
				{
					buffer[i] = '%'; i++; format++;
				}

			// handle each data type
			if (*format == 'c')
				buffer[i] = va_arg(list, int);
			if (*format == 's')
				append_buffer(buffer, va_arg(list, char*), i);

			format++;
			i++;
		}
	}
	write(1, buffer, i+5);
	return (0);
}
/*
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
    //_printf("Unknown:[%r]\n");
    //printf("Unknown:[%r]\n");
    return (0);
} */

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;


	char c = 'H';
	char *s = "World!";
	_printf("LALALALA %c ello %s\n", c, s);

	return (0);

}
