#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
int main(void)
{
	printf("a%.0i\n",0);
	ft_printf("b%.0i\n",0);

	return (0);
}
