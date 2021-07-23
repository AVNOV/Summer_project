#include <unistd.h>
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

int	my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return(0);
}

int main(void)
{
    my_putstr("Lorem ipsum");
    return 0;
}