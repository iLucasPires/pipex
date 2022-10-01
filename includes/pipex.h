#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/includes/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

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
}			t_data;

typedef struct s_child
{
	int		fd[2];
	int		pid;
	int		status;
}			t_child;

typedef struct s_path
{
	int		index[2];
	char	*aux[2];
	char	**path_dirs;
}			t_path;

char		*get_cmd_path(const char *cmd, char **envp);
void		free_array(char **array);
void		error(char *str, void *ptr);
void		handle_argv(int argc, char **argv);
void		destruct_data(t_data *d);
void		child_process(t_data *d);
void		last_process(t_data *d);

#endif