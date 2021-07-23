#ifndef MINISHELL_H_
#define MINISHELL_H_

#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct env_s
{
    char *line_ptr;
    struct env_s *next;
} t_env;

ssize_t	my_strlen(char const *str, const char separator);
int my_putstr(char const *str);
int my_strncmp(char const *s1, char const *s2, int nb);
char *my_strdup(char* str);
char *my_strcpy(char *dest, char const *src);
char *str_concat(char *s1, char *s2);

void print_env(t_env *list);
void clean_env_list(t_env *list);
int prepare_access(char **path_tab, char **input_cmd, char **env);
void kill_or_fill_access(char **input, char *line, char **path, char **env);
t_env *create_env_list(char **env);
t_env *add_env_node_to_list(t_env *list, char *env_line);
char **get_path(t_env **env);

int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char *str, char c);

#endif /* !MINISHELL_H_ */
