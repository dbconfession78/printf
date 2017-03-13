#include "holberton.h"

// flips order of characters in a string
char *reverseStr(char string[]) {
	char *result = malloc(strlen(string));

	for(int i=0; i<strlen(string); i++) {
		result[i] = string[strlen(string)-1-i];
	}

	return result;
}
