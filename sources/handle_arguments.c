#include "../includes/library.h"

void	handle_argv(int argc, char **argv)
{
	if (argc < 5)
	{
		ft_putstr_fd("pipex: too few arguments\n", 2);
		exit(1);
	}
}

void	destruct_data(char **mtx, char *array)
{
	int		index;

	index = 0;
	while (mtx[index])
		free(mtx[index++]);
	free(mtx);
	free(array);
}
