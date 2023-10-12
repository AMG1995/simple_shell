/**
 **_strncpy - copies a string
 *@pest: the destination string to be copied to
 *@sour: the source string
 *@max: the maximum number of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *pest, char *sour, int max)
{
    char *s = pest;
    int i = 0;

    if (max > 0) {
        do {
            pest[i] = sour[i];
            i++;
        } while (sour[i - 1] != '\0' && i < max);
        while (i < max) {
            pest[i] = '\0';
            i++;
        }
    }

    return s;
}

/**
 **_strncat - concatenates two strings
 *@pest: the first string
 *@sour: the second string
 *@max: the maximum number of bytes to be used for concatenation
 *Return: the concatenated string
 */
char *_strncat(char *pest, char *sour, int max)
{
    char *s = pest;
    int i = 0;
    int j = 0;

    if (max > 0) {
        do {
            while (pest[i] != '\0') {
                i++;
            }
            do {
                pest[i] = sour[j];
                i++;
                j++;
            } while (sour[j - 1] != '\0' && j < max);
            if (j < max) {
                pest[i] = '\0';
            }
        } while (j < max);
    }

    return s;
}
/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
    do
    {
        if (*s == c)
        {
            return s;
        }
    } while (*s++ != '\0');

    return NULL;
}
