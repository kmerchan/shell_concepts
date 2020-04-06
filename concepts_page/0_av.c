#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	int i;

	for (i = 0; argv[i]; i++)
		printf("%s\n", argv[i]);
	return (0);
}
