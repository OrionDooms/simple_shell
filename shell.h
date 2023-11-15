#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define MAX_ARGS 64
extern char **environ;
int shell_loop(char *cp, char **env);
int _execve(char *str, char *name, char **env);
int _strcmp(char *s1, char *s2);
int _strcspn(char *str1, char *str2);
int del_string(char *str, char *word);
int _strlen(char *s);
int _putchar(char c);
int  hashtag(char *str, char *hash);
void commands(char *str, char *cp, char **env);
void Remove_quote(char *str, char *cp, char **env);
int find_quotation(const char *str);
void Remove_space(char *str, char *cp, char **env);
char *my_strtok(char *str, const char *delim);

ssize_t my_gline(char **line, size_t *n, FILE *stream);
void exits(int status);
void execmd(char **av);
#endif
