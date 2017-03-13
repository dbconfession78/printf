#ifndef STRCPERCENT_H
#define STRCPERCENT_H
#include "holberton.h"

int put_char(char *buffer, va_list list)
{

	return(1);
}

int put_string(char *buffer, va_list list)
{
	int i;
	char *str = va_arg(list, char*);
	char *nil = "(nil)";
	if (str)
	{
		for (i = 0; i < _strlen(str); i++)
			buffer[i] = str[i];
		return (i);
	}

	for (i = 0; i < 6; i++)
		buffer[i] = nil[i];

	return(6);
}

int put_percent(char *buffer, va_list list)
{
	buffer[0] = '%';
	return(1);
}

int put_int(char *buffer, va_list list)
{

	return(1); // TODO calc length to return
}

int put_float(char *buffer, va_list list)
{

	return(1); // calc length to return
}

int put_hex(char *buffer, va_list list)
{

	return(1); // calc length to return
}

int put_binary(char *buffer, va_list list)
{

	return(1); // calc length to return
}

int put_oct(char *buffer, va_list list)
{

	return(1); //calc length to return
}
#endif
