#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("a%.p\n",NULL);
	ft_printf("b%.p\n",NULL);
	return (0);
}
