#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "struct.h"

char *get_cmd_path(const char *cmd, char **envp);
void free_array(char **array);
void error(char *str, void *ptr);
void handle_argv(int argc, char **argv);
void destruct_data(t_data *d);
void child_process(t_data *d);
void last_process(t_data *d);

#endif