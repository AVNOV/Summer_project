#include "minishell.h"
#include "get_next_line.h"

static char *check_and_alloc(char **s1, char *s2, const char sep)
{
    char *new = NULL;
    int	i = 0;
    int	in_string = 0;

    new = malloc(my_strlen(s1 != NULL ? *s1 : NULL, sep) +
    my_strlen(s2, sep) + 1);
    if (new == NULL || ((s1 == NULL || *s1 == NULL) && s2 == NULL)) return (NULL);
    if (s1 && *s1)
        while ((*s1)[i] != '\0' && (*s1)[i] != sep)
            new[in_string++] = (*s1)[i++];
    i = 0;
    if (s2)
        while (s2[i] != '\0' && s2[i] != sep)
            new[in_string++] = s2[i++];
    new[in_string] = '\0';
    if (s1 && *s1) {
        free(*s1);
        *s1 = NULL;
    }
    return (new);
}

char *put_in_tmp(char **tmp)
{
    char * line = NULL;

    line = check_and_alloc(NULL, *tmp, '\n');
    while (**tmp && **tmp != '\n')
        (*tmp)++;
    (*tmp)++;
    if (**tmp == 0)
        *tmp = NULL;
    return (line);
}

char *get_next_line(int fd)
{
    static char	*tmp = NULL;
    char buf[READ_SIZE + 1];
    char *line = NULL;
    int size = 1;

    if (tmp != NULL)
        return (put_in_tmp(&tmp));
    while (size != 0) {
        if ((size = read(fd, buf, READ_SIZE)) < 0)
            return (NULL);
        buf[size] = 0;
        if (size != 0 && my_strlen(buf, '\n') != my_strlen(buf, 0)) {
            tmp = check_and_alloc(&tmp, &buf[my_strlen(buf, '\n') + 1], 0);
            return (check_and_alloc(&line, buf, '\n'));
        }
        else if (size != 0)
            line = check_and_alloc(&line, buf, 0);
        else if (size == 0) return (my_strdup(tmp));
    }
    return (line);
}