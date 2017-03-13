#include "holberton.h"

// converts integer to a chracter array
char *itoa(int n) {
	char *result = malloc(128);
	char *final = malloc(128);
	int i, sign;

	if((sign = n) < 0) {
		n = -n;
	}
	i = 0;
	do {
		result[i++] = (n % 10) + '0';
	} while((n /= 10) > 0);
	if(sign < 0) {
		result[i++] = '-';
	}
	result[i] = '\0';
	final  = reverseStr(result);
	return final;
}
