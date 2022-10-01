#include "../includes/pipex.h"

void	error(char *str, void *ptr)
{
	ft_putstr_fd(str, 2);
	if (ptr)
		free(ptr);
	exit(1);
}

void	handle_argv(int argc, char **argv)
{
	if (access(argv[1], F_OK))
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(1);
	}
}

void	destruct_data(t_data *d)
{
	free_array((void *)d->cmd_arg);
	free(d->cmd_path);
}