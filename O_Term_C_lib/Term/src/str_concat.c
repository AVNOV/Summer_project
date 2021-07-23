#include "minishell.h"
#include "get_next_line.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest, 0);

    while(src[i]) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}

char *str_concat(char *s1, char *s2)
{
    int first = my_strlen(s1, 0);
    int second = my_strlen(s2, 0);
    char *dest = malloc(sizeof(char) * (first + second) + 1);

    if (!dest)
        return (NULL);
    dest = my_strcpy(dest, s1);
    dest = my_strcat(dest, s2);
    return (dest);
}