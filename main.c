#include "simple_shell.h"

int main(void)
{
	char delims[] = " ", *line = NULL, *env, *av[1024] = {NULL};
	int a = 0;
	size_t len = 0;
	pid_t child_pid = 0;
	struct stat st;
	env = _gentenv("PATH");
	while (getline(&line, &len, stdin) > 0)
	{
		line = clear_line(line);
		a = nb_token(line, delims);
		printf("%d\n", a);
		av[0] = strtok(line, delims);

		for (int i = 1; i < a; i++)
			av[i] = strtok(NULL, delims);
		av[0] = _which(env, av[0]);
		if (av[0] == NULL)
		{
			printf("command not found\n");
		}
		else
			_exec(av);
	}


free(line);
return (EXIT_SUCCESS);
}
