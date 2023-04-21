#include "simple_shell.h"

char *_gentenv(const char *name)
{
	for (int i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, 4) == 0)
			return (environ[i]);
	}
	return (0);
}

char getpath(char *path, char *cmd)
{
	const char EQUAL[2] = "=";
	char COLUMN[2] = ":";
	int nb = 0;
	struct stat st;

	path = strtok(path, EQUAL);
	path = strtok(NULL, EQUAL);
	path = strtok(path, COLUMN);

	while (path)
	{
		path = _strcat(path, cmd);
		if (!stat(path, &st))
			return (path);
		else
			path = strtok(NULL, COLUMN);
	}
	return (path);
}
