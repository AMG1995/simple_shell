/**
 * _strncpy - Copies a string.
 * @dest: The destination string to be copied to.
 * @src: The source string.
 * @n: The maximum number of characters to be copied.
 *
 * Return: The concatenated string.
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	char *original_dest = dest;
	
	while (n > 0 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	
	return original_dest;
}

/**
 * _strncat - Concatenates two strings.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to be used for concatenation.
 *
 * Return: The concatenated string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	char *original_dest = dest;
	
	while (*dest != '\0')
		dest++;
	
	while (n > 0 && *src != '\0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	
	if (n > 0)
		*dest = '\0';
	
	return original_dest;
}

/**
 * _strchr - Locates a character in a string.
 * @s: The string to be parsed.
 * @c: The character to look for.
 *
 * Return: A pointer to the memory area s.
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (char *)s;
		s++;
	}

	return NULL;
}
