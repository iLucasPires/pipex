/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:24:55 by lpires-n          #+#    #+#             */
/*   Updated: 2022/10/10 15:00:45 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/library.h"

void	handle_argv(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("pipex: too few arguments\n", 2);
		exit(1);
	}
	else if (argc > 5)
	{
		ft_putstr_fd("pipex: too many arguments\n", 2);
		exit(1);
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
