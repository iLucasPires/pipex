/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:24:55 by lpires-n          #+#    #+#             */
/*   Updated: 2022/10/10 15:54:29 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/library_bonus.h"

void	handle_argv(int argc)
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
