#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *string = "Hi";
	int i = 0;
	pid_t check;

	check = fork();
	printf("%d\n", check);
	if (check > 0)
		wait(&check);

	else
	{
		for (i = 0; string[i]; i++)
		{
			printf("%c\n", string[i]);
		}
	}

	return(0);
}
