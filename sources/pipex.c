#include "../includes/library.h"

void	init_variable(t_data *d, int argc, char **argv, char **envp)
{
	d->argc = argc;
	d->argv = argv;
	d->envp = envp;
	d->cmd_count = argc - 3;
	d->cmd_index = 2;
	d->file[0] = open(argv[1], O_RDONLY, 0777);
	d->file[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
}

char	**find_cmd_path(char *argv)
{
	int		i;
	char	*aux;
	char	**aux_split;

	i = 0;
	aux_split = ft_split(argv, ' ');
	while (aux_split[i])
	{
		aux = aux_split[i];
		aux_split[i] = ft_strtrim(aux, "'");
		free(aux);
		i++;
	}
	return (aux_split);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	d;

	handle_argv(argc, argv);
	init_variable(&d, argc, argv, envp);
	while (d.cmd_index < d.cmd_count + 2)
	{
		d.cmd_arg = find_cmd_path(argv[d.cmd_index]);
		d.cmd_path = get_cmd_path(d.cmd_arg[0], envp);
		if (d.cmd_index == d.cmd_count + 1)
			last_process(&d);
		else
			child_process(&d);
		destruct_data(d.cmd_arg, d.cmd_path);
		d.cmd_index++;
	}
	return (0);
}
