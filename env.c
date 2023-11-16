#include "shell.h"
/**
 * print_env - displays the values of environment.
 * @env: takes in environment variables.
 */
void print_env(char **env)
{
	env = environ;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
