#include <stddef.h>

static size_t my_strlen(char *str);

char *my_strncat(char *dest, char *src, int nb)
{
    int len = my_strlen(dest);
    int i = 0;

    while(i < nb && src[i] != '\0') {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}