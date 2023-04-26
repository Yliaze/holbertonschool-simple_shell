#include "simple_shell.h"
/**
 * clear_line - Removes trailing newline character
 * from a string
 * @str: The string to modify
 * Return: A pointer to the modified string
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

/**
 * nb_token - Counts the number of tokens in a string
 * @str: The string to count tokens in
 * @delims: A string containing the delimiters
 * Return: The number of tokens in the string
 */
int nb_token(char *str, char *delims)
{
	int i = 0, y = 0, nb_token = 0;

	if (!str)
		return (0);

	while (delims[y])
	{
		if (delims[y] != str[0])
			nb_token = 1;
		y++;
	}

	while (str[i])
	{
		y = 0;
		while (delims[y])
		{
			if (str[i] == delims[y] && str[i + 1] != delims[y] && str[i + 1] != '\0')
			nb_token++;

			y++;
		}
		i++;
	}
	return (nb_token);
}
