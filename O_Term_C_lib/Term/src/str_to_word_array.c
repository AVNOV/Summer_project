#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_show_word_array(char * const *tab)
{
    while (*tab) {
        write(1, *tab, strlen(*tab));
        write(1, "\n", 1);
        tab++;
    }
    return (0);
}

int count_len(char *str, int start, char c)
{
    int i = 0;

    while ((str[start] != c) && (str[start] != '\0')) {
        start++;
        i++;
    }
    return (i);
}

int count_word(char *str, char c)
{
    int i = 0;
    int count = 0;
    char test_char = c;
    
    while (str[i] != '\0') {
        if ((test_char == c) && (str[i] != c))
            count++;
        test_char = str[i];
        i++;
    }
    return (count);
}

char *my_strncpy(char *str, char *dest, int start, char c)
{
    int i = 0;

    while ((str[start] != c) && (str[start] != '\0')) {
        dest[i] = str[start];
        start++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char **my_str_to_word_array(char *str, char c)
{
    int   i = 0;
    int   j = 0;
    char  test_char = c;
    char  **dest;

    if ((dest = malloc(sizeof(dest) * (count_word(str, c) + 1))) == 0)
        return (NULL);
    while (str[i] != '\0') {
        if ((test_char == c) && (str[i] != c)) {
            dest[j] = malloc(sizeof(**dest) * (count_len(str, i, c) + 1));
            my_strncpy(str, dest[j], i, c);
            j++;}
	
        test_char = str[i];
        i++;
    }
    dest[j] = NULL;
    return (dest);
}
