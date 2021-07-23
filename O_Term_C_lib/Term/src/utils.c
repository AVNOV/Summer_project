#include "minishell.h"

ssize_t	my_strlen(char const *str, const char separator)
{
    ssize_t size = 0;

    if (str != NULL)
        while (str[size] && str[size] != separator)
            size++;
    return (size);
}

int my_putstr(char const *str)
{
    return (write(1, str, my_strlen(str, 0)));
}

int	my_strncmp(char const *s1, char const *s2, int nb)
{
    int i = 0;
    int j = 0;

    if (!s2)
        return (1);
    if (nb > 0) {
        while (s1[i] && s2[j] && nb > 0) {
            if (s1[i] != s2[j])
                return (s1[i] - s2[j]);
        i++;
        j++;
        nb--;
        }
    }
    return (0);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char *str)
{
	int len;
	char *dup = NULL;

    if (str == NULL)
        return (NULL);
    len = my_strlen(str, 0) + 1;
    dup = malloc(sizeof(char) * len);
	if (dup == NULL)
		return (NULL);
	dup = my_strcpy(dup, str);
	dup[len - 1] = '\0';
	return (dup);
}