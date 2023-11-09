#include "shell.h"
/**
 * my_getline - Reads an entire line from stream.
 * @line: Storing the address contants the text into **line.
 * @n: is a pointer that keeps the array’s size.
 * @f: is the stream from which the file will be read.
 * Return: The number of characters read.
 */
ssize_t my_getline(char **line, size_t *n, FILE *f)
{
	int c;
	size_t i = 0, new_size, temp = 0;
	char *buf_size, *new_ptr;

	if (line == NULL || n == NULL || f == NULL)
		return (-1);
	if (*line == NULL || *n == 0)
	{
		*n = 128;
		*line = (char *)malloc(*n);
		if (*line == NULL)
		{
			return (-1);
		}
	}
	buf_size = *line;
	while ((c = read(fileno(f), &buf_size[i], 1)) > 0)
	{
		if (i >= (*n - 1))
		{
			new_size = (*n) * 2;
			new_ptr = (char *)realloc(*line, new_size);
			if (new_ptr == NULL)
			{
				return (-1);
			}
			*line = new_ptr;
			*n = new_size;
			buf_size = *line;
		}
		if (buf_size[i] == '\n')
			break;
		i++;
		temp++;
	}
	if (temp <= 0)
		return (temp);
	buf_size[i] = '\0';
	return (temp);
}
