#include "simple_shell.h"
/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of pointers to the arguments
 * Return: Always 0 (success)
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	char delims[] = " ", *line = NULL, *env;
	int a = 0, i = 0, exist = 1;
	size_t len = 0;
	char *path_cpy = NULL;
	struct stat st;

	env = _gentenv("PATH=");
	while (getline(&line, &len, stdin) > 0)
	{
		char *av[1024] = {NULL};

		line = clear_line(line);
		__exit(line);
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
				_exec(av, &exist);
			}
			else if (env && !exist)
			{
				path_cpy = copy_path(env);
				av[0] = _which(path_cpy, av[0], &exist);
				if (exist)
					_exec(av, &exist), free(av[0]);
				free(path_cpy);
			}
			if (!exist)
				error(argv[0], av[0], env);
		}
	}
	free(line);
	return (EXIT_SUCCESS);
}
