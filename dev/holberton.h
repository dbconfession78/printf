#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct directive
{
	char ch;
	int (*f)(char *buffer, va_list list);
} dir;

int get_int_len(int value);
int _strlen(char *s);
char *itoa(int n);
char *reverseStr(char string[]);
void reset_buffer(char *buffer, int size);
int put_char(char *buffer, va_list list);
int put_string(char *buffer, va_list list);
int put_percent(char *buffer, va_list list);
int (*get_directive_function(char c))(char *s, va_list);
int put_int(char *buffer, va_list list);
int put_hex_lower(char *buffer, va_list list);
int put_hex_upper(char *buffer, va_list list);
char *uitohex(unsigned int);
int put_binary(char *buffer, va_list list);
int put_float(char *buffer, va_list list);
int put_oct(char *buffer, va_list list);
#endif
