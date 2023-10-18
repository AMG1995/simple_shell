#include "shell.h"

/**
 * write_stderr - Writes an input string to stderr.
 * @str: The string to be written.
 *
 * Return: Nothing.
 */
void write_stderr(char *str)
{
	int i;

	if (!str)
		return;

	for (i = 0; str[i] != '\0'; i++)
	{
		write_stderr_char(str[i]);
	}
}

/**
 * write_stderr_char - Writes a character to stderr.
 * @c: The character to print.
 *
 * Return: On success, 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_stderr_char(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}

	return (1);
}

/**
 * write_to_fd - Writes a character to a given file descriptor.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * Return: On success, 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_to_fd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}

	return (1);
}

/**
 * write_string_to_fd - Writes an input string to a given file descriptor.
 * @str: The string to be written.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters written.
 */
int write_string_to_fd(char *str, int fd)
{
	int i, j = 0;

	if (!str)
		return (0);

	for (j = 0; str[j] != '\0'; j++)
	{
		i += write_to_fd(str[j], fd);
	}

	return i;
}
