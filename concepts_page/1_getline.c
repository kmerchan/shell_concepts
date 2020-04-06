#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	size_t BUFF_SIZE = 1024;
	char *buffer;

	buffer = malloc(sizeof(char) * BUFF_SIZE);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "ERROR: Unable to allocate buffer");
		exit(98);
	}

	printf("$ ");
	getline(&buffer, &BUFF_SIZE,stdin);
	printf("%s", buffer);
	return(0);
}
