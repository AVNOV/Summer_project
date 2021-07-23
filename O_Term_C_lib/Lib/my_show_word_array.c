
#include <unistd.h>

int my_putstr(char *str);

int my_show_word_array(char * const *tab)
{
    int i = 0;
    
    while (tab[i] != 0) {
        my_putstr(tab[i]);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}
