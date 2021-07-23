#include <stddef.h>

static size_t my_strlen(char *str)
{
    char *tmp = NULL;

    if (!str)
        return (-1);
    tmp = str;
    while (*tmp != '\0')
        tmp++;
    return (tmp - str);
}