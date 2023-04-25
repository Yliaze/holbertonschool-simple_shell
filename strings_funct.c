#include "simple_shell.h"

/**
 * _strcat - Concatenates two strings
 * @s1: The first string
 * @s2: The second string
 * Return: A pointer to the resulting string
 */
char *_strcat(char *s1, char *s2)
{
	size_t len_s1 = strlen(s1);
    size_t len_s2 = strlen(s2);
    size_t len_separator = sizeof(char);
	
    char *result = calloc(len_s1 + len_s2 + len_separator + 1, sizeof(char));
    if (result == NULL) {
        exit(1);
    }

    strcpy(result, s1);
    strcat(result, "/");
    strcat(result, s2);
    return result;
}

/**
 * string_size - Calculates the size of a string, including the null byte
 * @str: The string to calculate the size of
 * Return: The size of the string, including the null byte
 */
int string_size(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
		return (i + 1);
}

/**
 * _strcpy - Copies a string
 * @dest: The destination string
 * @src: The source string
 * Return: A pointer to the destination string
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
 * cut_string - Splits a string into tokens using a
 * set of delimiters
 * @str: The string to split
 * @delims: A string containing the delimiters
 * @av: An array of strings to store the tokens
 */
void cut_string(char *str, char *delims, char **av)
{
	int i = 1;

	av[0] = strtok(str, delims);
	for (; str; i++)
	{
		av[i] = strtok(NULL, delims);
	}
}
