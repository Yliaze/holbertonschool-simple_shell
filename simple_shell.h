#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>

extern char **environ;

void cut_string(char *str, char *delims, char **av);
char *_strcpy(char *dest, char *src);
char *_strcat(char *s1, char *s2);
char *clear_line(char *str);
int nb_token(char *str, char *delims);
char *_gentenv(const char *name);
char *_which(char *path, char *cmd, int *exist);
void _exec(char **av);
int string_size(char *str);
int error(char *program, char *cmd, char *env, char *line);

#endif