#include "shell.h"

/**
 * isExecutableCommand - Checks if a file is an executable command
 * @info: The info struct
 * @filePath: The path to the file
 *
 * Return: 1 if the file is an executable command, 0 otherwise
 */
int isExecutableCommand(info_t *info, char *filePath)
{
    struct stat fileStat;

    (void)info;
    if (!filePath || stat(filePath, &fileStat) != 0)
        return 0;

    if (S_ISREG(fileStat.st_mode))
    {
        return 1;
    }
    return 0;
}

/**
 * duplicateSubstring - Duplicates a substring from a string
 * @sourceString: The source string
 * @startIndex: The starting index of the substring
 * @endIndex: The ending index of the substring
 *
 * Return: Pointer to a new buffer containing the duplicated substring
 */
char *duplicateSubstring(char *sourceString, int startIndex, int endIndex)
{
    static char buffer[1024];
    int sourceIndex = startIndex;
    int bufferIndex = 0;

    for (; sourceIndex < endIndex; sourceIndex++)
    {
        if (sourceString[sourceIndex] != ':')
        {
            buffer[bufferIndex++] = sourceString[sourceIndex];
        }
    }

    buffer[bufferIndex] = '\0';
    return buffer;
}

/**
 * findExecutableInPath - Finds the full path of a command in the PATH environment variable
 * @info: The info struct
 * @pathString: The PATH environment variable
 * @command: The command to find
 *
 * Return: The full path of the command if found, or NULL if not found
 */
char *findExecutableInPath(info_t *info, char *pathString, char *command)
{
    int sourceIndex = 0;
    int currentPos = 0;
    char *fullPath;

    if (!pathString)
        return NULL;

    if ((stringLength(command) > 2) && stringStartsWith(command, "./"))
    {
        if (isExecutableCommand(info, command))
            return command;
    }

    while (1)
    {
        if (!pathString[sourceIndex] || pathString[sourceIndex] == ':')
        {
            fullPath = duplicateSubstring(pathString, currentPos, sourceIndex);

            if (!*fullPath)
                stringConcatenate(fullPath, command);
            else
            {
                _strcat(fullPath, "/");
                _strcat(fullPath, command);
            }

            if (isExecutableCommand(info, fullPath))
                return fullPath;

            if (!pathString[sourceIndex])
                break;

            currentPos = sourceIndex;
        }
        sourceIndex++;
    }

    return NULL;
}
