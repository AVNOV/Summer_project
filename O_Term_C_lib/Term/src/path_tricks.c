#include "minishell.h"

char **get_path(t_env **env)
{
    char **stored_path = NULL;
    char *path = NULL;

    while (*env) {
        if (!my_strncmp("PATH", (*env)->line_ptr, 5)) {
            path = my_strdup(&(*env)->line_ptr[5]);
	    stored_path = my_str_to_word_array(path, ':');
	    return (stored_path);
	}
	(*env) = (*env)->next;
    }
    return (NULL);
}
