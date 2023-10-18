#include "shell.h"

/**
 * stringCopy - copies a string
 * @destination: the destination
 * @source: the source
 *
 * Return: pointer to the destination
 */
char *stringCopy(char *destination, char *source)
{
    int i;
    if (destination == source || source == 0)
        return destination;
    
    for (i = 0; source[i]; i++)
    {
        destination[i] = source[i];
    }
    
    destination[i] = 0;
    
    return destination;
}

/**
 * stringDuplicate - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *stringDuplicate(const char *str)
{
    int length = 0;
    char *result;
    
    if (str == NULL)
        return NULL;

    while (*str++)
        length++;

    result = malloc(sizeof(char) * (length + 1));
    
    if (!result)
        return NULL;
    
    for (length++; length--;)
        result[length] = *--str;
    
    return result;
}

/**
 * printString - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
    int i = 0;

    if (!str)
        return;

    for (i = 0; str[i] != '\0'; i++)
    {
        _putchar(str[i]);
    }
}

/**
 * writeCharacter - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    static int i;
    static char buffer[WRITE_BUF_SIZE];

    if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
    {
        write(1, buffer, i);
        i = 0;
    }

    if (c != BUF_FLUSH)
    {
        buffer[i++] = c;
    }

    return 1;
}
