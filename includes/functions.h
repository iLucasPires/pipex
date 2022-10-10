/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:43:17 by lpires-n          #+#    #+#             */
/*   Updated: 2022/10/10 15:00:17 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "struct.h"

char	*get_cmd_path(const char *cmd, char **envp);
void	free_array(char **array);
void	error(char *str, void *ptr);
void	handle_argv(int argc);
void	child_process(t_data *d);
void	last_process(t_data *d);
void	destruct_data(char **mtx, char *array);
#endif