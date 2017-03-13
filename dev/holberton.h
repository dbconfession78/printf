#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct directive
{
	char ch;
	int (*f)(char *buffer, va_list list);
} dir;

int _strlen(char *s);
void reset_buffer(char *buffer, int size);
int put_char(char *buffer, va_list list);
int put_string(char *buffer, va_list list);
int put_percent(char *buffer, va_list list);

int (*get_directive_function(char c))(char *s, va_list);
int put_int(char *buffer, va_list list);
int put_hex(char *buffer, va_list list);
int put_binary(char *buffer, va_list list);
int put_float(char *buffer, va_list list);
int put_oct(char *buffer, va_list list);

#endif
