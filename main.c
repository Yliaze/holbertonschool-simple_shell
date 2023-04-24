#include "simple_shell.h"

int main(void)
{
	char delims[] = " ", *line = NULL, *env, *av[1024] = {NULL};
	int a = 0, i;
	size_t len = 0;
	char *quelquechose;
	struct stat st;

	while (getline(&line, &len, stdin) > 0)
	{
		line = clear_line(line);
		a = nb_token(line, delims);
		av[0] = strtok(line, delims);

		for (i = 1; i < a; i++)
			av[i] = strtok(NULL, delims);

		if (stat(av[0], &st) == 0)
		{
			_exec(av);
		}
		else
		{
			env = _gentenv("PATH");
			quelquechose = strdup(env);
			av[0] = _which(quelquechose, av[0]);
			if (av[0] != NULL)
			{
				_exec(av);
				free(av[0]);
			}
			free(quelquechose);
			quelquechose = strdup(env);
		}
	}
	free(line);
	free(quelquechose);
	return (EXIT_SUCCESS);
}
