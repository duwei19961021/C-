#include <stdio.h>
#include <ctype.h>

char *strlowr(char *str)
{
    char *orign=str;
    for (; *str!='\0'; str++)
        *str = tolower(*str);
    return orign;
}

int main(int argc, char * argv[])
{
	int i;
	for (i = 1; i<argc; i++)
	{
		printf("%s\n",strlowr(argv[i]));
	}
	return 0;
}
