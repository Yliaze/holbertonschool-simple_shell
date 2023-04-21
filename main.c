#include "simple_shell.h"

int main(void)
{
	char delims[] = " ", *line = NULL, *env;
	int a = 0;
	size_t len = 0;
	pid_t child_pid = 0;
	struct stat st;
	//env = _gentenv("PATH");
	
	while (getline(&line, &len, stdin) > 0)
	{
		line = clear_line(line);
		
		//printf("%s\n", line );
	// 	a = nb_token(line, delims);

	// 	if (a)
	// 	{

	// 	}
	// }
	// free(line);
	return (EXIT_SUCCESS);
}
