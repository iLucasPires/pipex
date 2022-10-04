#ifndef STRUCT_H
# define STRUCT_H

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