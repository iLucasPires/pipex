/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:43:22 by lpires-n          #+#    #+#             */
/*   Updated: 2022/10/11 00:18:46 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_BONUS_H
# define LIBRARY_BONUS_H

# include "../libft/includes/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# define INPUT 0
# define OUTPUT 1
# define CHILD 0
# define SPACE_NULL 1
# define ERROR_CMD 127

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**cmd_arg;
	char	*cmd_path;
	int		cmd_count;
	int		cmd_index;
	int		file[2];
	int		status;
}			t_data;

typedef struct s_cmd
{
	int		index;
	char	*path;
	char	**dirs;
	char	*cmd_path;
}			t_cmd;

typedef struct s_child
{
	int		fd[2];
	int		pid;
	int		status;
}			t_child;

char		*get_cmd_path(const char *cmd, char **envp);
void		free_array(char **array);
void		error(char *str, void *ptr);
void		handle_argv(int argc);
void		child_process(t_data *d);
void		last_process(t_data *d);
void		destruct_data(char **mtx, char *array);

#endif