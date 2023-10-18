#include "shell.h"

/**
 ** fillMemory - Fills memory with a constant byte
 *@destination: The pointer to the memory area
 *@byte: The byte to fill *destination with
 *@size: The number of bytes to be filled
 * Return: (destination) A pointer to the memory area destination
 */
char *fillMemory(char *destination, char byte, unsigned int size)
{
	unsigned int i;

	for (i = 0; i < size; i++)
		destination[i] = byte;
	return (destination);
}

/**
 * freeStringArray - Frees an array of strings
 * @stringArray: The array of strings
 */
void freeStringArray(char **stringArray)
{
	char **temp = stringArray;

	if (!stringArray)
		return;
	while (*stringArray)
		free(*stringArray++);
	free(temp);
}

/**
 * reallocateMemory - Reallocates a block of memory
 * @oldBlock: Pointer to the previously allocated memory block
 * @oldSize: Byte size of the previous block
 * @newSize: Byte size of the new block
 *
 * Return: Pointer to the newly allocated memory block
 */
void *reallocateMemory(void *oldBlock, unsigned int oldSize, unsigned int newSize)
{
	char *newBlock;

	if (!oldBlock)
		return (malloc(newSize));
	if (!newSize)
		return (free(oldBlock), NULL);
	if (newSize == oldSize)
		return (oldBlock);

	newBlock = malloc(newSize);
	if (!newBlock)
		return (NULL);

	oldSize = oldSize < newSize ? oldSize : newSize;
	while (oldSize--)
		newBlock[oldSize] = ((char *)oldBlock)[oldSize];
	free(oldBlock);
	return (newBlock);
}
