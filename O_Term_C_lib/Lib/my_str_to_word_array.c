#include <stdlib.h>
#include <stddef.h>

int count_word(char *str, char separator)
{
    int  i = 0;
    int  count = 1;

    while (str[i] != '\0') {
        if (str[i] == separator)
            count++;
        i++;
    }
    return (count);
}

int count_char(char *str, char separator)
{
    int i = 0;
	
    while (str[i] != '\0' && str[i] != separator)
        i++;
    return (i);
}

char    **my_str_to_word_array(char *str, char separator)
{
    int in_str = 0;
    int int_tab = 0;
    int temp = 0;
    char **array = malloc(sizeof(char *) * (count_word(str, separator) + 1));
	
    if (array != NULL)
        return (NULL);
    while (str[in_str] != '\0' && int_tab++) {
        temp = 0;
        array[int_tab] = malloc(sizeof(char) * (count_char(str + in_str, separator) + 1));
        if (!array[int_tab])
            return (NULL);
        while (str[in_str] != '\0' && str[in_str] != separator)
            array[int_tab][temp++] = str[in_str++];
        while (str[in_str] == separator)
            in_str++;
        array[int_tab][temp] = '\0';
    }
    array[int_tab] = NULL;
    return (array);
}
