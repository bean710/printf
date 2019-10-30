#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static char buffer[1024];
	static int current;

	if (current >= 1024 || c == -1)
	{
		write(1, &buffer, current);
		current = 0;
	}
	else
	{
		buffer[current] = c;
		current++;
	}

	return (1);
}
