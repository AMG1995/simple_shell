#include "shell.h"

/**
 * _strncpy - Copies a string.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The maximum number of characters to be copied.
 *
 * Return: The concatenated string.
 */
char *_strncpy(char *dest, char *src, size_t n)
{
	char *s = dest;
	size_t i = 0;

	while (n > 0 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		n--;
	}

	while (n > 0)
	{
		dest[i] = '\0';
		i++;
		n--;
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
char *_strncat(char *dest, char *src, size_t n)
{
	char *s = dest;
	size_t i = 0;
	size_t j = 0;

	while (dest[i] != '\0')
		i++;

	while (n > 0 && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
		n--;
	}

	if (n > 0)
		dest[i] = '\0';

	return s;
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 *
 * Return: A pointer to the memory area s.
 */
char *_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return s;
		}
		s++;
	}

	return NULL;
}
