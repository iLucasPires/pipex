/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:28:43 by lpires-n          #+#    #+#             */
/*   Updated: 2022/10/11 00:24:48 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_variable(t_data *d, int argc, char **argv, char **envp)
{
	d->argc = argc;
	d->argv = argv;
	d->envp = envp;
	d->cmd_count = argc - 3;
	d->cmd_index = 2;
	d->file[0] = open(argv[1], O_RDONLY, 0777);
	d->file[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (d->file[1] == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[argc - 1], 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(1);
	}
}

char	**filter_argv(char *cmd)
{
	int		index;
	char	*temp;
	char	**cmd_arg;
	int		active_quote;

	index = 0;
	active_quote = 1;
	while (cmd[index])
	{
		if (cmd[index] == '\'')
			active_quote = !active_quote;
		else if (cmd[index] == ' ' && active_quote)
			cmd[index] = SPACE_NULL;
		index++;
	}
	cmd_arg = ft_split(cmd, SPACE_NULL);
	index = 0;
	while (cmd_arg[++index])
	{
		temp = cmd_arg[index];
		cmd_arg[index] = ft_strtrim(temp, "'");
		free(temp);
	}
	return (cmd_arg);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	handle_argv(argc);
	init_variable(&data, argc, argv, envp);
	while (data.cmd_index < data.cmd_count + 2)
	{
		data.cmd_arg = filter_argv(argv[data.cmd_index]);
		data.cmd_path = get_cmd_path(data.cmd_arg[0], envp);
		if (data.cmd_index == data.cmd_count + 1)
			last_process(&data);
		else
			child_process(&data);
		destruct_data(data.cmd_arg, data.cmd_path);
		data.cmd_index++;
	}
	exit((data.status >> 8) & 0xFF);
	return (0);
}
