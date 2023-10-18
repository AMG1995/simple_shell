#include "shell.h"

/**
 * _strncpy - Copies a string.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The maximum number of characters to be copied.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;
	char *s = dest;

<<<<<<< HEAD
	if (n > 0)
	{
		do
		{
			dest[i] = src[i];
			i++;
		}
		while (src[i - 1] != '\0' && i < n);
=======
	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
>>>>>>> 55470f28ee2d30efcbff9da40f9bcce2650ac3fe
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
 * Return: A pointer to the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

<<<<<<< HEAD
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
=======
	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
>>>>>>> 55470f28ee2d30efcbff9da40f9bcce2650ac3fe
	}
	if (j < n)
		dest[i] = '\0';
	return s;
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 *
 * Return: A pointer to the memory area of the character in the string.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return s;
		s++;
	}
	return NULL;
}
