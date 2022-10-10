/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpires-n <lpires-n@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:43:35 by lpires-n          #+#    #+#             */
/*   Updated: 2022/10/10 15:01:50 by lpires-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# define INPUT 0
# define OUTPUT 1
# define CHILD 0
# define SPACE_NULL 1

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
	int		error;
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

#endif