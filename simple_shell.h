#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>

char **cut_string(char *str, char *delims, int nb_token);
char *_strcpy(char *dest, char *src);
char *_strcat(char *s1, char *s2);
char *clear_line(char *str);
int nb_token(char *str, char *delims);
char *get_path(char **envp);
char **clear_path(char *path);
char *check_for_func(char *cmd, char **envp);


#endif
