#include <stdio.h>
#include <stdlib.h>

int test(char *str)
{
	str[0] = 'n';
	return (0);
}

int main(void)
{	
	char str[];
	str = "pah";
	printf("%s",str);
	test(str);
	printf("%s",str);
}