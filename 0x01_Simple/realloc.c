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
    unsigned int i = 0;

    while (i < size) {
        destination[i] = byte;
        i++;
    }
    return destination;
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
    while (*stringArray) {
        free(*stringArray++);
    }
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
        return malloc(newSize);
    if (!newSize)
        return free(oldBlock), NULL;
    if (newSize == oldSize)
        return oldBlock;

    newBlock = malloc(newSize);
    if (!newBlock)
        return NULL;

    unsigned int minSize = oldSize < newSize ? oldSize : newSize;
    unsigned int i = 0;
    while (i < minSize) {
        newBlock[i] = ((char *)oldBlock)[i];
        i++;
    }

    free(oldBlock);
    return newBlock;
}
