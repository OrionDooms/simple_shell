#include "shell.h"
/**
 * commands - Takes in commands and interpeter for the used
 * to communicate with the system.
 * @str: Takes in a string.
 * @cp: Takes arguments.
 * @env: The current environment.
 */
void commands(char *str, char *cp, char **env)
{
	char *token;
	char *args[MAX_ARGS];
	char copy[2000];
	int i = 0, a = 1;
	const char *e = getenv("PATH");

	strcpy(copy, str);
	token = my_strtok(str, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = my_strtok(NULL, " ");
	}
	args[i] = NULL;
	if ((strcmp(args[0], "echo") == 0) || (strcmp(args[0], "/bin/echo") == 0))
	{
		if (strcmp(args[1], "$$") == 0)
			printf("%d\n", (int)getpid());
		else if (strcmp(args[1], "$PATH") == 0)
			printf("%s\n", e);
		else if (strcmp(args[1], "exit") == 0)
			exits(98);
		else if (find_quotation(copy) == 0)
			Remove_quote(copy, cp, env);
		else
		{
			while (args[a])
			{
				printf("%s ", args[a]);
				a++;
			}
			printf("\n");
		}
	}
	else if (strncmp(copy, " ", 1) == 0)
		Remove_space(copy, cp, env);
	else if (find_quotation(copy) == 0)
		Remove_quote(copy, cp, env);
	else
		_execve(copy, cp, env);
}
/**
 * Remove_space - Remove spaces from the string.
 * @str: takes in a string.
 * @env: display your current environment.
 * @cp: Takes arguments.
 */
void Remove_space(char *str, char *cp, char **env)
{
	int i, c = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
			str[c++] = str[i];
	}
	str[c] = '\0';
	commands(str, cp, env);
}
/**
 * find_quotation - find quotation in a string.
 * @str: takes in a string.
 * Return: 0 (success) 1 (Error).
 */
int find_quotation(const char *str)
{
	while (*str != '\0')
	{
		if (*str == '"')
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 * Remove_quote - Remove quotation from the string.
 * @str: takes in a string.
 * @env: display your current environment.
 * @cp: Takes arguments.
 */
void Remove_quote(char *str, char *cp, char **env)
{
	int i, c = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != '"')
			str[c++] = str[i];
	}
	str[c] = '\0';
	commands(str, cp, env);
}
