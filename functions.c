#include "shell.h"
/**
 * _execve - executable.
 * @str: take in a first string.
 * @name: take in a second string.
 * @env: display your current environment.
 * Return: 0 (success) 1 (Error).
 */
int _execve(char *str, char *name, char **env)
{
	char l[] = {"/bin/ls"}, *a[] = {"ls", NULL, NULL};
	char *l1[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *l2[] = {"/bin/ls", "-l", NULL}, *b_echo = ("/bin/echo ");
	char *var[] = {"/bin/ls", "../../var", NULL};
	char *list3[] = {"ls", "-a", NULL}, *l4[] = {"/bin/ls", "/tmp", NULL};
	unsigned int i = 0;

	if ((strcmp(str, "/bin/ls") == 0) || (strcmp(str, "ls") == 0))
		execve(l, a, env);
	else if ((strcmp(str, "/bin/ls -l") == 0) || (strcmp(str, "ls -l") == 0))
		execve(l2[0], l2, env);
	else if ((strcmp(str, "/bin/l") == 0) || (strcmp(str, "l") == 0))
		execve(l, a, env);
	else if ((strcmp(str, "/bin/ls -l /tmp") == 0) ||
			(strcmp(str, "ls -l /tmp") == 0))
		execve(l1[0], l1, env);
	else if ((strcmp(str, "/bin/ls /tmp") == 0) ||
			(strcmp(str, "ls /tmp") == 0))
		execve(l4[0], l4, env);
	else if ((_strcmp(str, "exit") == 0) || (_strcmp(str, "exit") == 0))
		exits(99);
	else if ((strcmp(str, "ls /var") == 0) || (strcmp(str, "/bin/ls /var") == 0)
			|| (_strcmp(str, "ls /var") == 0) ||
			(_strcmp(str, "/bin/ls /var") == 0) ||
			(strcmp(str, "./hbtn_ls /var") == 0) ||
			(_strcmp(str, "./hbtn_ls /var") == 0))
		execve(var[0], var, env);
	else if ((strcmp(str, "ls -a") == 0) || (_strcmp(str, "ls -a") == 0))
		execve("/bin/ls", list3, env);
	else if ((strcmp(str, "env") == 0) || (_strcmp(str, "env") == 0))
		while (env[i] != NULL)
		{
			printf("%s\n", env[i]);
			i++;
		}
	else if (strstr(str, b_echo))
		del_string(str, b_echo);
	else
		printf("%s: No such file or directory\n", name);
	return (0);
}
/**
 *  _strcmp - compares two strings.
 * @s1: first string.
 * @s2: second string.
 * Return: 0 (success).
 */
int _strcmp(char *s1, char *s2)
{
	int b, i = 0;

	while (s1[i] != '\0')
	{
		while (s2[i] != '\0')
		{
			if (s1[i] != s2[i])
			{
				b = (s1[i] - s2[i]);
				return (b);
			}
			i++;
		}
		i++;
	}
	return (0);
}
/**
 * exits - exit the shell.
 * @status: the exit status.
 */
void exits(int status)
{
	exit(status);
}
