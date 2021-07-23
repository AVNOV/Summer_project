#include <stddef.h>

static size_t my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    if ((!str || !to_find) || (my_strlen(str) < my_strlen(to_find)))
        return NULL;
    while (str[i] != '\0' && str[0] != '\0' ) {
        j = 0;
        while (str[i + j] == to_find[j] && (to_find[j] != '\0' && str[i + j] != '\0'))
            j++;
        if (to_find[j] == '\0') 
            return (&str[i]);
        i++;
    }
    return NULL;
}