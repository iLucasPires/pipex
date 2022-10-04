#include "../includes/library.h"

char	*get_acess_cmd(const char *path, char **dirs)
{
	t_cmd	c;

	c.index = 0;
	while (dirs[c.index])
	{
		c.cmd_path = ft_strjoin(dirs[c.index], path);
		if (!access(c.cmd_path, F_OK))
			return (c.cmd_path);
		free(c.cmd_path);
		c.index++;
	}
	return (NULL);
}
       
char	*get_cmd_path(const char *cmd, char **envp)
{
	t_cmd c;

	c.index = 0;
	while (ft_strncmp(envp[c.index], "PATH=", 5))
		c.index++;
	c.path = ft_strjoin("/", cmd);
	c.dirs = ft_split(envp[c.index] + 5, ':');
	c.cmd_path = get_acess_cmd(c.path, c.dirs);
	destruct_data(c.dirs, c.path);
	return (c.cmd_path);
}