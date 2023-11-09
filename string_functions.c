#include "shell.h"
/**
 * del_string - delete a word from a string.
 * @str: takes in a string.
 * @word: takes in word
 * Return: returns the string with a word.
 */
int del_string(char *str, char *word)
{
	int sl = _strlen(str), k, i, j = 0;

	for (i = 0; i < sl; i++)
	{
		while (str[i] == word[j] && word[j] != '\0')
		{
			for (k = i; str[k] != '\0'; k++)
			{
				str[k] = str[k + 1];
			}
			j++;
		}
	}
	printf("%s", str);
	return (0);
}
/**
 * _strlen - finds the length of a string.
 * @s: takes in a string.
 * Return: returns the length of a string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _putchar - writes the character c to stdout.
 * @c: The character to print.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * hashtag - find the hashtag in the string.
 * @str: takes in a string.
 * @hash: hashtag symbol.
 * Return: 0 (success).
 */
int hashtag(char *str, char *hash)
{
	del_string(str, hash);
	return (0);
}
