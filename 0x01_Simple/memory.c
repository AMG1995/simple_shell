#include "shell.h"

/**
 * pointer_free - frees a pointer and NULLs value
 * @ptr: address of the pointer.
 *
 * Return: 1 if freed, otherwise 0.
 */
int pointer_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
