#include "../includes/library.h"

void	child_process(t_data *d)
{

	
	t_child	c;

	pipe(c.fd);
	c.pid = fork();
	if (c.pid == 0)
	{
		close(c.fd[0]);
		close(d->file[1]);
		dup2(d->file[0], STDIN_FILENO);
		dup2(c.fd[1], STDOUT_FILENO);
		execve(d->cmd_path, d->cmd_arg, d->envp);
	}
	close(c.fd[1]);
	waitpid(c.pid, &c.status, 0);
	d->file[0] = c.fd[0];
}

void	last_process(t_data *d)
{
	t_child	c;

	c.pid = fork();
	if (c.pid == 0)
	{
		dup2(d->file[0], STDIN_FILENO);
		dup2(d->file[1], STDOUT_FILENO);
		execve(d->cmd_path, d->cmd_arg, NULL);
	}
	waitpid(c.pid, &c.status, 0);
	close(d->file[0]);
	close(d->file[1]);
}
