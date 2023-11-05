#include "shell.h"
/**
 * my_strtok - breaks string into tokens using the delimiter.
 * @str: Takes in a string.
 * @delim: it is a string containing all delimiters.
 * Return: returns a pointer to the first token found then to
 * the next token.
 */
char *my_strtok(char *str, const char *delim)
{
	static char *c;
	int i;

	if (str != NULL)
		c = str;
	else
		str = c;
	if (*c == '\0')
		return (NULL);
	while (*c != '\0')
	{
		i = 0;
		while (delim[i] != '\0')
		{
			if (*c == delim[i])
			{
				if (c == str)
				{
					c++;
					str++;
				}
				else
				{
					*c = '\0';
					break;
				}
			}
			i++;
		}
		if (*c == '\0')
		{
			c++;
			return (str);
		}
		c++;
	}
	return (str);
}
