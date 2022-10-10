/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_process_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:23:54 by lpires-n          #+#    #+#             */
/*   Updated: 2022/10/10 20:21:54 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/library_bonus.h"

void	execute(t_data *data)
{
	if (data->file[INPUT] != -1 && data->cmd_path)
		execve(data->cmd_path, data->cmd_arg, data->envp);
	else
	{
		ft_putstr_fd(data->argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		destruct_data(data->cmd_arg, data->cmd_path);
		exit(127);
	}
}

void	child_process(t_data *d)
{
	t_child	c;

	if (pipe(c.fd) == -1)
	{
		ft_putstr_fd("Pipe error\n", 2);
		exit(1);
	}
	c.pid = fork();
	if (c.pid == CHILD)
	{
		close(c.fd[INPUT]);
		close(d->file[OUTPUT]);
		dup2(d->file[INPUT], STDIN_FILENO);
		dup2(c.fd[OUTPUT], STDOUT_FILENO);
		execute(d);
	}
	close(c.fd[OUTPUT]);
	close(d->file[INPUT]);
	waitpid(c.pid, &d->status, 0);
	d->file[INPUT] = c.fd[INPUT];
}

void	last_process(t_data *d)
{
	t_child	c;

	c.pid = fork();
	if (c.pid == CHILD)
	{
		dup2(d->file[INPUT], STDIN_FILENO);
		dup2(d->file[OUTPUT], STDOUT_FILENO);
		execute(d);
	}
	close(d->file[OUTPUT]);
	close(d->file[INPUT]);
	waitpid(c.pid, &d->status, 0);
}