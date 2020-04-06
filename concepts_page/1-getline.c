#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	ssize_t BUFF_SIZE = 10;
	char *buffer;
	ssize_t rd, wr;
	ssize_t count = 0;
	char *dollar = "$ ";
	size_t size = 2;

	wr = write(STDOUT_FILENO, dollar, size);
	if (wr < 0)
	{
		dprintf(STDERR_FILENO, "ERROR: Unable to write\n");
		exit(97);
	}

	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "ERROR: Unable to allocate buffer\n");
		exit(98);
	}

	rd = read(STDIN_FILENO, buffer, BUFF_SIZE);
	if (rd < 0)
	{
		dprintf(STDERR_FILENO, "ERROR: Unable to read input\n");
		exit(99);
	}
	while (rd == BUFF_SIZE)
	{
		count += rd;
		buffer = realloc(buffer, sizeof(char) * (BUFF_SIZE + count));
		if (buffer == NULL)
		{
			dprintf(STDERR_FILENO, "ERROR: Unable to allocate buffer\n");
			exit(98);
		}
		rd = read(STDIN_FILENO, &buffer[count], BUFF_SIZE);
		if (rd < 0)
		{
			dprintf(STDERR_FILENO, "ERROR: Unable to read input\n");
			exit(99);
		}
	}
	printf("%s", buffer);
	return(0);
}
