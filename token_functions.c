#include "simple_shell.h"
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

/**
 * nb_token - count the number of token
 * @str: the string
 * @delims: separator of each tokens
 * Return: the number of token
 */
int nb_token(char *str, char *delims)
{
	int i = 0, y = 0, nb_token = 0;

	if (!str)
		return (0);
	
	while (delims[y])
	{
		if(delims[y] != str[0])
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
