#include "simple_shell.h"

char *get_path(char **envp)
{
	const char PATH[5] = "PATH";

	for (int i = 0; envp[i]; i++)
	{
		if (strncmp(envp[i], PATH, 4) == 0)
			return (envp[i]);
	}
	return (0);
}

char **clear_path(char *path)
{
	char **new_path = NULL;
	const char EQUAL[2] = "=";
	char COLUMN[2] = ":";
	int nb = 0;

	path = strtok(path, EQUAL);
	path = strtok(NULL, EQUAL);
	nb = nb_token(path, COLUMN);
	new_path = cut_string(path, COLUMN, nb);
	return (new_path);
}
char *check_for_func(char *cmd, char **envp)
{
	char *path = malloc (1204);
	struct stat st;
	int i = 0;

	while (envp[i])
	{
		path = _strcat(path, cmd);
		printf("%s \n", path);

		if(!stat(path, &st))
		{
			return (path);
		}
		i++;
	}
	return (NULL);
}
