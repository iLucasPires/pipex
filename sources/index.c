#include "../includes/pipex.h"

char *get_path(char **envp)
{
    int index;

    index = 0;
    while (envp[index])
    {
        if (ft_strncmp(envp[index], "PATH=", 5) == 0)
            return (envp[index] + 5);
        index++;
    }
    return (NULL);
}

char *get_cmd_path(const char *cmd, char **envp)
{
    int index;
    char *cmd_path;
    char **path_dirs;

    index = 0;

    path_dirs = ft_split(get_path(envp), ':');
    printf("path_dirs: %s\n", path_dirs[0]);
    while (path_dirs[index])
    {
        free(path_dirs[index]);
        index++;
    }
    free(path_dirs);

    return (NULL);
}

int main(int argc, char **argv, char **envp)
{
    t_data data;
    printf("command path: %s\n", get_cmd_path("ping", envp));
    return 0;
}
