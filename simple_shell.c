#include "simple_shell.h"

/**
 * _strcpy - copy a string
 * @src: point to strng to copy
 * @dest: the buffur contains the copy
 * Return: the 2nd buffer
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * cut_string - split a string at each delimiters
 * @str: the string
 * @delims: separator of each tokens
 * @nb_token: the number of token
 * Return: array of strings
 */
char **cut_string(char *str, char *delims, int nb_token)
{
	int i = 0;
	char **dest = NULL;
	char *res = NULL;

	dest = malloc(sizeof(char *) * (nb_token + 1));

	res = strtok(str, delims);
	while (res != NULL)
	{
		dest[i] = malloc(sizeof(char) * (strlen(res) + 1));
		_strcpy(dest[i], res);
		res = strtok(NULL, delims);
		i++;
	}
	dest[i] = ((char *)NULL);

	return (dest);
}

/**
 * nb_token - count the number of token
 * @str: the string
 * @delims: separator of each tokens
 * Return: the number of token
 */
int nb_token(char *str, char *delims)
{
	int i = 0, y = 0, nb_token = 1;

	while (str[i])
	{
		y = 0;
		while (delims[y])
		{
			if (str[i] == delims[y])
				nb_token++;

			y++;
		}
		i++;
	}
	return (nb_token);
}

/**
 * clear_line - remove the new line at the end of a string
 * @str: the string to clear
 * Return: the string without '\n'
 */
char *clear_line(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	if (str[i - 1] == '\n')
		str[i - 1] = '\0';

	return (str);
}

void free_all(char **tok, char *line)
{
	int i = 0;
	while (tok[i])
	{
		free(tok[i]);
		i++;
	}
	free(tok);
	free(line);
}

int main(__attribute__((unused)) int ac, __attribute__((unused)) char ** av, char **envp)
{
	char delims[] = " ", *line = NULL, **tok;
	int status, i;
	size_t len = 0;
	pid_t child_pid = 0;
	struct stat st;

	/*printf("$ ")*/
	while (getline(&line, &len, stdin) > 0)
	{
		clear_line(line);
		tok = cut_string(line, delims, nb_token(line, delims));

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
				printf("No such file or directory\n");
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
			free(tok);
			/*printf("$ ");*/
		}
	}
	free_all(tok, line);
	return (EXIT_SUCCESS);
}
