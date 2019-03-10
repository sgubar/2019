#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int a,i=0,count=1;
	char* mass = "Hello new country Ukraine";
	for(i=0;i<strlen(mass);i++)
	{
		if(mass[i]==' ')
			count++;
	}
	printf("%i",count);

	return 0;
}
