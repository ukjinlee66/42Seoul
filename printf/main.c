#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
	printf("a%-16.16s\n","abc");
	ft_printf("b%-16.16s\n","abc");

	return (0);
}
