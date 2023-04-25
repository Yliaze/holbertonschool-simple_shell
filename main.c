#include "simple_shell.h"

int main(int __attribute__((unused)) argc, char **argv)
{
	char delims[] = " \n", *line = NULL, *env, *av[1024] = {NULL}, *stock_av;
	int a = 0, i = 0, path_size, exist = 0;
	size_t len = 0;
	char *quelquechose = NULL;
	struct stat st;

	env = _gentenv("PATH=");
	path_size = string_size(env);
	while (getline(&line, &len, stdin) > 0)
	{
		line = clear_line(line);
		if (strcmp(line, "exit") == 0)
        	exit(0);
		a = nb_token(line, delims);

		if (a)
		{
			exist = 0;
			av[0] = strtok(line, delims);
			path_size = string_size(av[0]);
			stock_av = malloc(path_size + 1);
			stock_av = strcpy(stock_av, av[0]);

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
			{
				fprintf(stderr, "%s: 1: %s: not found\n", argv[0], av[0]);
				if (env)
					free(av[0]);
			}
			free(stock_av);
		}
	}
	free(line);
	return (EXIT_SUCCESS);
}