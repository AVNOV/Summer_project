#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

int run_execve_fc(char **env, char *path_tab, char **input_cmd)
{
    int i = 0;
    int test = 1;

    while (env[i] && ((test = my_strncmp("PATH", env[i], 5)) != 0))
        i++;
    if (test == 0) {
        execve(path_tab, input_cmd, env);
        return (0);
    }
    return (write(1, "NO FOLDER FOUND", 16));
}

int my_exec_fork(char **env, char *path_tab, char **input_cmd)
{
    int status = 0;
    pid_t pid;

    if ((pid = fork()) == -1)
        write(2, "Impossible, error with pid", 27);
    else if (pid == 0) {
        run_execve_fc(env, path_tab, input_cmd);
        return (0);
    }
    else {
        waitpid(pid, &status, 0);
    }
    return (0);
}

int check_access(char **path_tab, char **env, char **input_cmd)
{
    int rt = 0; 
    int i = 0;

    while (path_tab[i]) {
        rt = access(path_tab[i], F_OK);
        if (rt == 0) {
            if ((rt = access(path_tab[i], X_OK)) == 0) {
               my_exec_fork(env, path_tab[i], input_cmd);
               return (0);
            }
        }
        i++;
    }
    return (0);
}

int prepare_access(char **path_tab, char **input_cmd, char **env)
{
    int i = 0;

    while (path_tab[i]) {
        path_tab[i] = str_concat(path_tab[i], "/");
        path_tab[i] = str_concat(path_tab[i], input_cmd[0]);
        i++;
    }
    check_access(path_tab, env, input_cmd);
    return (0);
}

void kill_or_fill_access(char **input, char *line, char **path, char **env)
{
    input = my_str_to_word_array(line, ' ');
    prepare_access(path, input, env);
}
