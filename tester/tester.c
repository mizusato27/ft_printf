#include "../ft_printf.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

static void	ft_print_total_result(int success, int total)
{
	printf("Passed: %d / %d ", success, total);
    success == total ? printf("%s(SUCCESS)%s\n", GREEN, RESET) : printf("%s(FAILED)%s\n", RED, RESET);
	return ;
}

static int	ft_compare_results(int n1, int n2, int n3)
{
	if (n1 == n2)
	{
		printf("\n-- %d.%sOK%s (%d) --\n\n", n3, YELLOW, RESET, n1);
		return (1);
	}
	printf("\n-- %d.%sKO%s (%d, %d) --\n\n", n3, RED, RESET, n1, n2);
	return (0);
}

int	main(void)
{
	int	success = 0;
	int	total = 0;
	int	std;
	int	custom;

	printf("\n--------------- printf test ---------------\n\n");

	printf("[only %%]\n");
	// custom = printf("%");
	// printf("\n%d\n", custom);
	custom = ft_printf("%");
	printf("\n%d\n\n", custom);

	int	*ptr1 = NULL;
	printf("[*ptr == NULL]\n");
	total++;
	printf("std:\n");
	std = printf("%p", ptr1);
	printf("\ncustom:\n");
	custom = ft_printf("%p", ptr1);
	success += ft_compare_results(std, custom, total);

	int	num = 42;
	ptr1 = &num;
	printf("[*ptr == &num]\n");
	total++;
	printf("std:\n");
	std = printf("%p", ptr1);
	printf("\ncustom:\n");
	custom = ft_printf("%p", ptr1);
	success += ft_compare_results(std, custom, total);

	char c = '\0';
	char	*ptr2 = &c;
	printf("[*ptr == &c]\n");
	total++;
	printf("std:\n");
	std = printf("%p", ptr2);
	printf("\ncustom:\n");
	custom = ft_printf("%p", ptr2);
	success += ft_compare_results(std, custom, total);

	printf("[int +]\n");
	int	x = 12345;
	total++;
	printf("std:\n");
	std = printf("%d", x);
	printf("\ncustom:\n");
	custom = ft_printf("%d", x);
	success += ft_compare_results(std, custom, total);

	printf("[int -]\n");
	x = -12345;
	total++;
	printf("std:\n");
	std = printf("%d", x);
	printf("\ncustom:\n");
	custom = ft_printf("%d", x);
	success += ft_compare_results(std, custom, total);

	printf("[cspdiuxX%%]\n");
	x = 123;
	c = 'a';
	char	*str = "omg";
	total++;
	printf("std:\n");
	std = printf("%c%s%d%i%u%x%X%%", c, str, x, x, x, x, x);
	printf("\ncustom:\n");
	custom = ft_printf("%c%s%d%i%u%x%X%%", c, str, x, x, x, x, x);
	success += ft_compare_results(std, custom, total);

	ft_print_total_result(success, total);

	printf("\n-------------------------------------------\n\n");
	return (0);
}
