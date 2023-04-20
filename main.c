#include "simple_shell.h"

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv, char **envp)
{
	char delims[] = " ", *line = NULL, **av, **env;
	int status, i, a = 0;
	size_t len = 0;
	pid_t child_pid = 0;
	struct stat st;
	env = clear_path(get_path(envp));
	while (getline(&line, &len, stdin) > 0)
	{
		printf("env[2] = %s\n",env[2]);
		clear_line(line);
		a = nb_token(line, delims);
		if (a)
		{
			av = cut_string(line, delims, a);
			av[0] = check_for_func(av[0], env);
			
			printf("av[0] = %s\n",av[0]);
			printf("env[2] = %s\n",env[2]);

			_exec(av, envp);

			free(av);
		}
	}
	free(line);
	return (EXIT_SUCCESS);
}
