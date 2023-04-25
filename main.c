#include "simple_shell.h"

int main(int __attribute__((unused)) argc, char **argv)
{
	char delims[] = " \n", *line = NULL, *env;
	int a = 0, i = 0, path_size, exist = 0;
	size_t len = 0;
	char *quelquechose = NULL;
	struct stat st;

	env = _gentenv("PATH=");
	while (getline(&line, &len, stdin) > 0)
	{
		char *av[1024] = {NULL};

		line = clear_line(line);
		if (strcmp(line, "exit") == 0)
		{
			free(line);
			exit(0);
		}
		a = nb_token(line, delims);
		if (a)
		{

			exist = 0;
			av[0] = strtok(line, delims);
			for (i = 1; i < a; i++)
				av[i] = strtok(NULL, delims);
			if (stat(av[0], &st) == 0)
			{
				exist = 1;
				_exec(av);
			}
			else if (env && !exist)
			{
				path_size = string_size(env);
				quelquechose = malloc(path_size + 1);
				quelquechose = strcpy(quelquechose, env);
				av[0] = _which(quelquechose, av[0], &exist);
				if (exist)
				{
					_exec(av);
					free(av[0]);
				}
				free(quelquechose);
			}
			if (!exist)
				error(argv[0], av[0], env, line);
		}
	}
	free(line);
	return (EXIT_SUCCESS);
}