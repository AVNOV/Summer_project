#include "minishell.h"

void clean_env_list(t_env *list)
{
    if (list->next)
        clean_env_list(list->next);
    free(list);
}

void print_env(t_env *list)
{
    t_env *temp = list;

    if (temp == NULL) {
        write(1, "[NULL]\n", 7);
        return;
    }
    while (temp->next != NULL) {
        write(1, "[", 1);
        my_putstr(temp->line_ptr);
        write(1, "]", 1);
        write(1, "\n", 1);
        temp = temp->next;
    }
}