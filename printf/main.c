#include "includes/ft_printf.h"
#include <stdio.h>
int main(void)
{
	printf("pr:%d\n",printf("%.0s\n ","abc"));
	printf("ft:%d\n",ft_printf("%.0s\n ","abc"));
	return (0);
}
