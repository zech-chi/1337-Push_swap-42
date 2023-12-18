#include <stdio.h>

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (av[1][0] == '\n')
		printf("yes\n");
	else
		printf("no\n");
	return (0);
}
