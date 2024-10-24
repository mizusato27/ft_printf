#include <stdio.h>

int	main(void)
{
	int	num = 42;
	int	*ptr = &num;
	int	std;

	std = printf("%p\n", (void *)ptr);
	printf("%d\n", std);

	// std = printf("%");
	// printf("\n%d\n", std);
	return (0);
}
