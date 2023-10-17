#include "shell.h"

/**
 * bufferInput - buffers chained commands
 * @info: parameter struct
 * @buffer: address of buffer
 * @length: address of length var
 *
 * Return: bytes read
 */
ssize_t bufferInput(info_t *info, char **buffer, size_t *length)
{
    ssize_t bytesRead = 0;
    size_t len_p = 0;

    if (!*length) /* If nothing left in the buffer, fill it */
    {
        free(*buffer);
        *buffer = NULL;
        signal(SIGINT, handleSIGINT);
#if USE_GETLINE
        bytesRead = getline(buffer, &len_p, stdin);
#else
        bytesRead = customGetline(info, buffer, &len_p);
#endif
        if (bytesRead > 0)
        {
            if ((*buffer)[bytesRead - 1] == '\n')
            {
                (*buffer)[bytesRead - 1] = '\0'; /* Remove trailing newline */
                bytesRead--;
            }
            info->lineCountFlag = 1;
            removeComments(*buffer);
            buildHistoryList(info, *buffer, info->histCount++);
            *length = bytesRead;
            info->commandBuffer = buffer;
        }
    }
    return bytesRead;
}

/**
 * getInput - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t getInput(info_t *info)
{
    static char *buffer; /* The ';' command chain buffer */
    static size_t currentIndex, j, length;
    ssize_t bytesRead = 0;
    char **bufferPointer = &(info->arg), *commandStart;

    _putchar(BUFFER_FLUSH);
    bytesRead = bufferInput(info, &buffer, &length);
    if (bytesRead == -1) /* EOF */
        return -1;
    if (length) /* We have commands left in the chain buffer */
    {
        j = currentIndex; /* Init new iterator to current buffer position */
        commandStart = buffer + currentIndex; /* Get pointer for return */

        checkChain(info, buffer, &j, currentIndex, length);
        while (j < length) /* Iterate to semicolon or end */
        {
            if (isChain(info, buffer, &j))
                break;
            j++;
        }

        currentIndex = j + 1; /* Increment past nulled ';'' */
        if (currentIndex >= length) /* Reached end of buffer? */
        {
            currentIndex = length = 0; /* Reset position and length */
            info->commandBufferType = COMMAND_NORMAL;
        }

        *bufferPointer = commandStart; /* Pass back pointer to current command position */
        return _strlen(commandStart); /* Return length of current command */
    }

    *bufferPointer = buffer; /* Else not a chain, pass back buffer from customGetline() */
    return bytesRead; /* Return length of buffer from customGetline() */
}

/**
 * readBuffer - reads a buffer
 * @info: parameter struct
 * @buffer: buffer
 * @currentIndex: size
 *
 * Return: bytesRead
 */
ssize_t readBuffer(info_t *info, char *buffer, size_t *currentIndex)
{
    ssize_t bytesRead = 0;

    if (*currentIndex)
        return 0;
    bytesRead = read(info->readfd, buffer, READ_BUFFER_SIZE);
    if (bytesRead >= 0)
        *currentIndex = bytesRead;
    return bytesRead;
}

/**
 * customGetline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: size
 */
int customGetline(info_t *info, char **ptr, size_t *length)
{
    static char buffer[READ_BUFFER_SIZE];
    static size_t currentIndex, length;
    size_t k;
    ssize_t bytesRead = 0, size = 0;
    char *p = NULL, *newPointer = NULL, *c;

    p = *ptr;
    if (p && length)
        size = *length;
    if (currentIndex == length)
        currentIndex = length = 0;

    bytesRead = readBuffer(info, buffer, &length);
    if (bytesRead == -1 || (bytesRead == 0 && length == 0))
        return -1;

    c = _strchr(buffer + currentIndex, '\n');
    k = c ? 1 + (unsigned int)(c - buffer) : length;
    newPointer = _realloc(p, size, size ? size + k : k + 1);
    if (!newPointer) /* MALLOC FAILURE! */
        return (p ? free(p), -1 : -1);

    if (size)
        _strncat(newPointer, buffer + currentIndex, k - currentIndex);
    else
        _strncpy(newPointer, buffer + currentIndex, k - currentIndex + 1);

    size += k - currentIndex;
    currentIndex = k;
    p = newPointer;

    if (length)
        *length = size;
    *ptr = p;
    return size;
}

/**
 * handleSIGINT - blocks ctrl-C
 * @signalNumber: the signal number
 *
 * Return: void
 */
void handleSIGINT(__attribute__((unused)) int signalNumber)
{
    _puts("\n");
    _puts("$ ");
    _putchar(BUFFER_FLUSH);
}
