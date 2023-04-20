#include "simple_shell.h"

/**
 * _strcpy - copy a string
 * @src: point to strng to copy
 * @dest: the buffur contains the copy
 * Return: the 2nd buffer
 */
char *_strcat(char *s1, char *s2)
{
	char *new_str = NULL;
	int i = 0, y = 0;

	new_str = malloc (sizeof(s1) + sizeof(s2) + 2);
	while (s1[i])
	{
		new_str[y] = s1[i];
		i++;
		y++;
	}
	i = 0;
	new_str[y] = '/';
	y++;
	while (s2[i])
	{
		new_str[y] = s2[i];
		i++;
		y++;
	}
	new_str[y] = '\0';
	return (new_str);
}

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
