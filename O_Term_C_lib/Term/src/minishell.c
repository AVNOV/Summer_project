#include "minishell.h"
#include "get_next_line.h"

char *check_for_input(void)
{
    char *buff = NULL;

    if ((buff = get_next_line(0)) == 0) {
        return NULL;
    }
    return (buff);

}

int turn_shell(t_env **dest_env, char **env)
{
    char *line = NULL;
    char **path_tab = NULL;
    char **input = NULL;

    //my_putstr("$>");
    while ((line = get_next_line(0)) != NULL) {
//        my_putstr("$>");
        path_tab = get_path(dest_env);
        if (my_strlen(line, 0) > 0) {
            kill_or_fill_access(input, line, path_tab, env);
//            my_putstr("$>");
        }
//            my_putstr("$>");
    }
    return (0);
}

int main(int ac, __attribute__((unused))char **av, char **env)
{
    t_env *dest_env = create_env_list(env);

    if (ac == 1) {
        turn_shell(&dest_env, env);
        clean_env_list(dest_env);
        return (0);
    }
    else
        return (84);    
}
