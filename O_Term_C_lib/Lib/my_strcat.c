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

char *my_strcat(char *dest, char const *src)
{
    int len = (int)my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}

