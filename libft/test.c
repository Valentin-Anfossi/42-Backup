#include <string.h>
#include <stdio.h>

int main(void)
{
	char *s = "tripouille";
	char *r = strchr(s,'t' + 256);
	
	printf("%c\n",'t'+256);

	printf("%s",r);
}