#include "../includes/pipex.h"

void	free_array(char **array)
{
	int	index;

	index = 0;
	while (array[index])
		free(array[index++]);
	free(array);
}

// char	*get_cmd_path(const char *cmd, char **envp)
// {
// 	t_path	p;

// 	p.index[0] = 0;
// 	p.index[1] = 0;
// 	while (ft_strncmp(envp[p.index[0]], "PATH=", 5))
// 		p.index[0]++;
// 	p.aux[0] = ft_strjoin("/", cmd);
// 	p.path_dirs = ft_split(envp[p.index[0]] + 5, ':');
// 	while (p.path_dirs[p.index[1]])
// 	{
// 		p.aux[1] = ft_strjoin(p.path_dirs[p.index[1]], p.aux[0]);
// 		if (!access(p.aux[1], F_OK))
// 		{
// 			free_array(p.path_dirs);
// 			free(p.aux[0]);
// 			return (p.aux[1]);
// 		}
// 		free(p.aux[1]);
// 		p.index[1]++;
// 	}
// 	return (NULL);
// }

char	*get_acess_cmd(const char *path, char **dirs)
{
	int		index;
	char	*aux;
	char	*cmd_path;

	index = 0;
	while (dirs[index])
	{
		cmd_path = ft_strjoin(dirs[index], path);
		if (!access(cmd_path, F_OK))
			return (cmd_path);
		free(cmd_path);
		index++;
	}
	return (NULL);
}

char	*get_cmd_path(const char *cmd, char **envp)
{
	int index;
	char *path;
	char **dirs;
	char *cmd_path;

	index = 0;
	while (ft_strncmp(envp[index], "PATH=", 5))
		index++;
	path = ft_strjoin("/", cmd);
	dirs = ft_split(envp[index] + 5, ':');
	cmd_path = get_acess_cmd(path, dirs);
	free(path);
	free_array(dirs);
	return (cmd_path);
}