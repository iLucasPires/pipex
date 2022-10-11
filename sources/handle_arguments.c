/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:24:55 by lpires-n          #+#    #+#             */
/*   Updated: 2022/10/10 21:32:55 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/library.h"

void	handle_argv(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("pipex: too few arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (argc > 5)
	{
		ft_putstr_fd("pipex: too many arguments\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	destruct_data(char **array_multi, char *array)
{
	int	index;

	index = 0;
	while (array_multi[index])
		free(array_multi[index++]);
	free(array_multi);
	free(array);
}

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
	t_cmd	c;

	c.index = 0;
	while (ft_strncmp(envp[c.index], "PATH=", 5))
		c.index++;
	c.path = ft_strjoin("/", cmd);
	c.dirs = ft_split(envp[c.index] + 5, ':');
	c.cmd_path = get_acess_cmd(c.path, c.dirs);
	destruct_data(c.dirs, c.path);
	return (c.cmd_path);
}
