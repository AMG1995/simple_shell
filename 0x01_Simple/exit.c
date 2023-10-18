#include "shell.h"

/**
 * _strncpy - Copies a string.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The maximum number of characters to be copied.
 *
 * Return: The concatenated string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *s = dest;
	int i = 0;

	if (n > 0)
	{
		do
		{
			dest[i] = src[i];
			i++;
		}
		while (src[i - 1] != '\0' && i < n);
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}

	return s;
}

/**
 * _strncat - Concatenates two strings.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to be used for concatenation.
 *
 * Return: The concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	char *s = dest;
	int i = 0;
	int j = 0;

	if (n > 0)
	{
		do
		{
			while (dest[i] != '\0')
			{
				i++;
			}
			do
			{
				dest[i] = src[j];
				i++;
				j++;
			} while (src[j - 1] != '\0' && j < n);
			if (j < n) {
				dest[i] = '\0';
			}
		} while (j < n);
	}

	return s;
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 *
 * Return: A pointer to the memory area s.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c) {
			return s;
		}
	} while (*s++ != '\0');

	return NULL;
}
