#ifndef PIPEX_H
#define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_data
{
    int file_descriptor[2];
    int process_id[2];
    int status;
    char **options;
}  t_data;


#endif