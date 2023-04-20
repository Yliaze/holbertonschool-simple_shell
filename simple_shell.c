#include "simple_shell.h"

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **envp)
{
	char delims[] = " ", *line = NULL, **tok, **env;
	int status, i, a = 0;
	size_t len = 0;
	pid_t child_pid = 0;
	struct stat st;

	/*printf("$ ")*/
	while (getline(&line, &len, stdin) > 0)
	{
		clear_line(line);
		a = nb_token(line, delims);
		if (a)
		{
			tok = cut_string(line, delims, a);
			env = clear_path(get_path(envp));
			tok[0] = check_for_func(tok[0], env);

			child_pid = fork();

			if (child_pid == -1)
				return (EXIT_FAILURE);

			else if (child_pid == 0)
			{
				if (!stat(tok[0], &st))
				{
					execve(tok[0], tok, envp);
				}
				else
				{
					return (0);
				}
			}

			else if (child_pid > 0)
			{
				wait(&status);
				i = 0;
				while (tok[i])
				{
					free(tok[i]);
					i++;
				}
				/*printf("$ ");*/
			}
			free(tok);
		}
	}
	free(line);
	return (EXIT_SUCCESS);
}
