#include "header.h"

/**
 * _strlen - determines the length of a string
 * @s: input character string to determine length of
 *
 * Return: byte count of length
 */

ssize_t _strlen(char *s)
{
	ssize_t i = 0;

	for (i = 0; s[i]; i++)
		continue;
	return (i);
}
