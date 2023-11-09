#include "shell.h"
/**
 * main - main for the Simple shell project.
 * @argc: number of arguments.
 * @argv: Takes arguments.
 * @env: The current environment.
 * Return: 0 (success).
 */
int main(int argc, char **argv, char **env)
{
	size_t agc = 0;
	char *cp = *argv, *str = NULL;

	if (argc)
	{
		if (isatty(fileno(stdin)))
			shell_loop(cp, env);
		else
		{
			my_getline(&str, &agc, stdin);
			commands(str, cp, env);
		}
	}
	return (0);
}
/**
 * _strcspn - str1 occurrence of any of the characters that are part
 * of str2, returning the number of characters of str1
 * @str1: the first string.
 * @str2: the second string.
 * Return: number of characters of str1.
 */
int _strcspn(char *str1, char *str2)
{
	int i, j;

	for (i = 0; str1[i] != '\0'; i++)
	{
		for (j = 0; str2[j] != '\0'; j++)
		{
			if (str1[i] == str2[j])
				return (i);
		}
	}
	return (i);
}
/**
 * shell_loop - create a shell loop.
 * @cp: Takes arguments.
 * @env: The current environment.
 * Return: 0 (success).
 */
int shell_loop(char *cp, char **env)
{
	size_t size = 0;
	char *prompt = "$ ", *buff = NULL;
	pid_t pid;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		if (my_getline(&buff, &size, stdin) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[_strcspn(buff, "\n")] = '\0';
		if (strcmp(buff, "exit") == 0)
		{
			free(buff);
			exit(0);
		}
		pid = fork();
		if (pid == 0)
		{
			commands(buff, cp, env);
			exit(2);
		}
		else if (pid > 0)
			wait(NULL);
		else
			perror("fork failed");
	}
	free(buff);
	return (0);
}
