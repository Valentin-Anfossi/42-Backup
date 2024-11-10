#include <string.h>
#include <stdio.h>

int main()
{
	char *test = strchr("Bonjour",'t' + 256);
	printf("%s",test);
}