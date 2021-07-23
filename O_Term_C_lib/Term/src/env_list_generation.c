#include "minishell.h"

t_env *add_env_node_to_list(t_env *list, char *env_line)
{
    t_env *new_node = malloc(sizeof(t_env));

    new_node->line_ptr = env_line;
    new_node->next = list;
    return (new_node);
}

t_env *add_env_node(t_env *last_node, char *env_line)
{
    t_env *new_node = malloc(sizeof(t_env));

    last_node->next = new_node;
    new_node->line_ptr = env_line;
    new_node->next = NULL;
    return (new_node);
}

t_env *first_env_node(char *env_line)
{
    t_env *list = malloc(sizeof(t_env));

    list->line_ptr = env_line;
    list->next = NULL;
    return (list);
}

t_env *create_env_list(char **env)
{
    t_env *new_list = first_env_node(env[0]);
    t_env *ptr_first_node = new_list;
    int	i = 1;

    while (env[i]) {
        new_list = add_env_node(new_list, env[i]);
        i++;
    }
    return (ptr_first_node);
}
